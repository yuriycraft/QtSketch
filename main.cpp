#include <QCoreApplication>
#include <QDirIterator>
#include <QDebug>
#include <QThread>

#include "Quazip/quazip.h"
#include "Quazip/quazipfile.h"

#include "utils.h"

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

    auto container = createContainer(file, parent);
    auto castedContainer = qobject_cast<T*>(container);

    if(castedContainer)
        return castedContainer;
    else
        throw QStringLiteral("not expected type");
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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

    QDirIterator iter(QStringLiteral("sketches"), QStringList { QStringLiteral("*.sketch") }, QDir::Files);
    while(iter.hasNext())
    {
        try
        {
            QuaZip zip(iter.next());

            qDebug() << zip.getZipName();

            if(!zip.open(QuaZip::mdUnzip))
                throw QStringLiteral("Could not open sketch file");

            auto document = createContainerZip<Document>(zip, QStringLiteral("document.json"));

            for(auto pageRef : document->pages())
            {
                auto page = createContainerZip<Page>(zip, pageRef->_ref() + ".json");
            }
        }
        catch(QString msg)
        {
            qCritical() << msg;
        }
    }

    return 0;
}
