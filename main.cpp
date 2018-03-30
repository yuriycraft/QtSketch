#include <QCoreApplication>
#include <QDirIterator>
#include <QDebug>
#include <QThread>

#include "utils.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

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
            getContainer(path);
        }
        catch(QString msg)
        {
            qCritical() << msg;
        }
    }

    return 0;
}
