#include <QApplication>
#include <QDirIterator>
#include <QTabWidget>
#include <QLabel>
#include <QDebug>

#include "Quazip/quazip.h"
#include "Quazip/quazipfile.h"

#include "containerfactory.h"

#include "container/document.h"
#include "container/msjsonfilereference.h"
#include "container/page.h"

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

            tabWidget->addTab(new QLabel(QStringLiteral("TODO"), tabWidget), page->name());
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
