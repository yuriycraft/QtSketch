#include <QApplication>
#include <QDirIterator>
#include <QTabWidget>
#include <QLabel>
#include <QGraphicsView>
#include <QDebug>

#include "sketchfile.h"
#include "container/document.h"
#include "container/page.h"
#include "container/msjsonfilereference.h"

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
        SketchFile file;

        auto filename = iter.next();
        try {
            file.open(filename);
        } catch(QString msg) {
            parentWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not load sketch file: %0</span>").arg(msg), parentWidget), filename);
            continue;
        }

        auto tabWidget = new QTabWidget(parentWidget);

        for(auto pageRef : file.document()->pages())
        {
            Page *page;
            try
            {
                page = file.loadPage(pageRef->_ref());
            } catch (QString msg) {
                tabWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not parse page: %0</span>").arg(msg), tabWidget), pageRef->_ref());
                continue;
            }

            QGraphicsScene *scene;
            try
            {
                scene = file.createScene(page);
            } catch (QString msg) {
                tabWidget->addTab(new QLabel(QStringLiteral("<span style=\"color: red;\">Could not render page: %0</span>").arg(msg), tabWidget), page->name());
                continue;
            }

            tabWidget->addTab(new QGraphicsView(scene, tabWidget), page->name());
        }

        parentWidget->addTab(tabWidget, file.filename());
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
