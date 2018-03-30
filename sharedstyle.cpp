#include "sharedstyle.h"

#include <QDebug>

SharedStyle::SharedStyle(QObject *parent) :
    BaseContainer(parent)
{
}

SharedStyle::SharedStyle(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
