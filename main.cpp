#include <QCoreApplication>
#include <QDirIterator>
#include <QDebug>
#include <QThread>

#include "utils.h"

#include "document.h"
#include "msjsonfilereference.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qSetMessagePattern("%{time dd.MM.yyyy HH:mm:ss.zzz} "
                       "["
                       "%{if-debug}D%{endif}"
                       "%{if-info}I%{endif}"
                       "%{if-warning}W%{endif}"
                       "%{if-critical}C%{endif}"
                       "%{if-fatal}F%{endif}"
                       "] "
                       "%{function}(): "
                       "%{message}");

    QDirIterator iter(
        QStringLiteral("sketches"),
        QStringList { QStringLiteral("document.json") },
        QDir::Files,
        QDirIterator::Subdirectories);

    while(iter.hasNext())
    {
        auto path = iter.next();
        qDebug() << path;

        try
        {
            auto document = createContainer<Document>(path);
            for(auto page : document->pages())
            {
            }
        }
        catch(QString msg)
        {
            qCritical() << msg;
        }
    }

    return 0;
}
