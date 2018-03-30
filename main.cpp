#include <QCoreApplication>
#include <QDirIterator>
#include <QDebug>
#include <QThread>

#include "utils.h"

#include "document.h"
#include "msjsonfilereference.h"
#include "page.h"

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

    QDirIterator iter(QStringLiteral("sketches"), QDir::Dirs);
    while(iter.hasNext())
    {
        QDir dir(iter.next());
        qDebug() << dir;

        try
        {
            auto document = createContainer<Document>(dir.absoluteFilePath(QStringLiteral("document.json")));
            for(auto pageRef : document->pages())
            {
                auto page = createContainer<Page>(dir.absoluteFilePath(pageRef->_ref() + ".json"));
            }
        }
        catch(QString msg)
        {
            qCritical() << msg;
        }
    }

    return 0;
}
