#include <QApplication>
#include <QDirIterator>
#include <QTabWidget>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QDebug>

#include "Quazip/quazip.h"
#include "Quazip/quazipfile.h"

#include "containerfactory.h"

#include "container/document.h"
#include "container/msjsonfilereference.h"
#include "container/page.h"
#include "container/rect.h"
#include "container/group.h"
#include "container/text.h"
#include "container/bitmap.h"
#include "container/rectangle.h"

template<typename T> T* createContainerZip(QuaZip &zip, const QString &filename, QObject *parent = Q_NULLPTR)
{
    if(!zip.setCurrentFile(filename))
        throw QStringLiteral("Could not set to %0").arg(filename);

    QuaZipFile file(&zip);
    if(!file.open(QIODevice::ReadOnly))
        throw QStringLiteral("Could not open %0 because %1").arg(filename, file.errorString());

    auto container = ContainerFactory::createContainer(file, parent);
    auto castedContainer = qobject_cast<T*>(container);

    if(castedContainer)
        return castedContainer;
    else
        throw QStringLiteral("not expected type");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qSetMessagePattern(QStringLiteral("%{time dd.MM.yyyy HH:mm:ss.zzz} "
                                      "["
                                      "%{if-debug}D%{endif}"
                                      "%{if-info}I%{endif}"
                                      "%{if-warning}W%{endif}"
                                      "%{if-critical}C%{endif}"
                                      "%{if-fatal}F%{endif}"
                                      "] "
                                      "%{function}(): "
                                      "%{message}"));

    auto parentWidget = new QTabWidget;

    QDirIterator iter(QStringLiteral("sketches"), QStringList { QStringLiteral("*.sketch") }, QDir::Files);
    while(iter.hasNext())
    {
        QuaZip zip(iter.next());

        qDebug() << zip.getZipName();

        if(!zip.open(QuaZip::mdUnzip))
            continue;

        Document *document;
        try {
            document = createContainerZip<Document>(zip, QStringLiteral("document.json"));
        } catch(QString msg) {
            parentWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not load document.json: %0</span>").arg(msg), parentWidget), zip.getZipName());
            continue;
        }

        auto tabWidget = new QTabWidget(parentWidget);

        for(auto pageRef : document->pages())
        {
            Page *page;
            try {
                page = createContainerZip<Page>(zip, pageRef->_ref() + ".json");
            } catch (QString msg) {
                tabWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not load %0: %1</span>").arg(pageRef->_ref(), msg), tabWidget), pageRef->_ref());
                continue;
            }

            auto minX = page->frame()->x(), minY = page->frame()->y(),
                 maxX = page->frame()->x() + page->frame()->width(),
                 maxY = page->frame()->y() + page->frame()->height();

            {
                std::function<void(Layer*,double&,double&,double&,double&,double,double)> getBounds;
                getBounds = [&getBounds](Layer *layer, double &minX, double &minY, double &maxX, double &maxY, double xOffset, double yOffset) {
                    auto x = xOffset + layer->frame()->x();
                    auto y = yOffset + layer->frame()->y();
                    if(minX > x)
                        minX = x;
                    if(minY > y)
                        minY = y;
                    if(maxX < x + layer->frame()->width())
                        maxX = x + layer->frame()->width();
                    if(maxY < y + layer->frame()->height())
                        maxY = y + layer->frame()->height();

                    if(auto group = qobject_cast<Group*>(layer))
                    {
                        for(auto subLayer : group->layers())
                            getBounds(subLayer, minX, minY, maxX, maxY, x, y);
                    }
                };

                getBounds(page, minX, minY, maxX, maxY, 0., 0.);
            }

            auto scene = new QGraphicsScene(minX, minY, maxX - minX + 1.,  maxY - minY + 1.);

            {
                std::function<void(Layer*,double,double)> createItem;
                createItem = [&createItem, &scene, &zip](Layer *layer,double xOffset, double yOffset){
                    if(auto text = qobject_cast<Text*>(layer))
                    {
                        auto textItem = scene->addText(text->name());
                        textItem->setPos(xOffset + text->frame()->x(), yOffset + text->frame()->y());
                    }
                    else if(auto bitmap = qobject_cast<Bitmap*>(layer))
                    {
                        auto path = bitmap->image()->_ref() + ".png";

                        if(!zip.setCurrentFile(path))
                        {
                            qWarning() << "could not unzip" << path;
                            return;
                        }

                        QuaZipFile file(&zip);
                        if(!file.open(QIODevice::ReadOnly))
                        {
                            qWarning() << "Could not open" << path << "because" << file.errorString();
                            return;
                        }

                        QImage image;
                        if(!image.load(&file, "PNG"))
                        {
                            qWarning() << "could not load image";
                            return;
                        }

                        auto bitmapItem = scene->addPixmap(QPixmap::fromImage(image.scaled(bitmap->frame()->width(), bitmap->frame()->height())));
                        bitmapItem->setPos(xOffset + bitmap->frame()->x(), yOffset + bitmap->frame()->y());
                    }
                    else if(auto group = qobject_cast<Group*>(layer))
                    {
                        for(auto subLayer : group->layers())
                            createItem(subLayer, xOffset + subLayer->frame()->x(), yOffset + subLayer->frame()->y());
                    }

                    scene->addRect(xOffset + layer->frame()->x(), yOffset + layer->frame()->y(),
                                   layer->frame()->width(), layer->frame()->height());
                };

                createItem(page, 0., 0.);
            }

            tabWidget->addTab(new QGraphicsView(scene, tabWidget), page->name());
        }

        parentWidget->addTab(tabWidget, zip.getZipName());
    }

    parentWidget->show();

    qDebug() << "summary of missing properties:";
    {
        const auto &missing = BaseContainer::missing();
        for(auto iter = missing.constBegin(); iter != missing.constEnd(); iter++)
            qDebug() << iter.key() << iter.value();
    }

    return a.exec();
}
