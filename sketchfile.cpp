#include "sketchfile.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

#include "quazip.h"
#include "quazipfile.h"

#include "containerfactory.h"

#include "container/document.h"
#include "container/msjsonfilereference.h"
#include "container/page.h"
#include "container/rect.h"
#include "container/group.h"
#include "container/text.h"
#include "container/bitmap.h"
#include "container/rectangle.h"

SketchFile::SketchFile(QObject *parent) :
    QObject(parent),
    m_document(Q_NULLPTR),
    m_zip(Q_NULLPTR)
{
}

const QString &SketchFile::filename() const
{
    return m_filename;
}

Document *SketchFile::document() const
{
    return m_document;
}

void SketchFile::open(const QString &filename)
{
    if(m_filename != filename)
        Q_EMIT filenameChanged(m_filename = filename);

    delete m_zip;

    m_zip = new QuaZip(filename);
    if(!m_zip->open(QuaZip::mdUnzip))
        throw tr("Could not unzip sketch file!");

    if(m_document)
        m_document->deleteLater();

    m_document = createContainerZip<Document>(QStringLiteral("document.json"), this);
    Q_EMIT documentChanged(m_document);
}

Page *SketchFile::loadPage(const QString &filename)
{
    return createContainerZip<Page>(filename + ".json", this);
}

QGraphicsScene *SketchFile::createScene(const QString &filename, QObject *parent)
{
    Page *page;
    try
    {
        page = loadPage(filename);
    } catch (QString msg) {
        throw tr("Could not parse page: %0").arg(msg);
    }

    QGraphicsScene *scene;
    try
    {
        scene = createScene(page, parent);
    } catch (QString msg) {
        throw tr("Could not render page: %0").arg(msg);
    }

    return scene;
}

QGraphicsScene *SketchFile::createScene(Page *page, QObject *parent)
{
    auto minX = page->frame()->x(), minY = page->frame()->y(),
         maxX = page->frame()->x() + page->frame()->width(),
         maxY = page->frame()->y() + page->frame()->height();

    getBoundsRecursive(page, minX, minY, maxX, maxY, 0., 0.);

    auto scene = new QGraphicsScene(minX, minY, maxX - minX + 1.,  maxY - minY + 1., parent);

    renderItemsRecursive(scene, page, 0., 0.);

    return scene;
}

void SketchFile::getBoundsRecursive(Layer *layer, double &minX, double &minY, double &maxX, double &maxY, double xOffset, double yOffset)
{
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
            getBoundsRecursive(subLayer, minX, minY, maxX, maxY, x, y);
    }
}

void SketchFile::renderItemsRecursive(QGraphicsScene *scene, Layer *layer, double xOffset, double yOffset)
{
    if(auto text = qobject_cast<Text*>(layer))
    {
        auto textItem = scene->addText(text->name());
        textItem->setPos(xOffset + text->frame()->x(), yOffset + text->frame()->y());
    }
    else if(auto bitmap = qobject_cast<Bitmap*>(layer))
    {
        auto path = bitmap->image()->_ref() + ".png";

        if(!m_zip->setCurrentFile(path))
        {
            qWarning() << "could not unzip" << path;
            return;
        }

        QuaZipFile file(m_zip);
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
            renderItemsRecursive(scene, subLayer, xOffset + subLayer->frame()->x(), yOffset + subLayer->frame()->y());
    }

    scene->addRect(xOffset + layer->frame()->x(), yOffset + layer->frame()->y(),
                   layer->frame()->width(), layer->frame()->height());
}

template<typename T>
T* SketchFile::createContainerZip(const QString &filename, QObject *parent)
{
    if(!m_zip->setCurrentFile(filename))
        throw QStringLiteral("Could not set to %0").arg(filename);

    QuaZipFile file(m_zip);
    if(!file.open(QIODevice::ReadOnly))
        throw QStringLiteral("Could not open %0 because %1").arg(filename, file.errorString());

    auto container = ContainerFactory::createContainer(file, parent);
    auto castedContainer = qobject_cast<T*>(container);

    if(castedContainer)
        return castedContainer;
    else
        throw QStringLiteral("not expected type");
}
