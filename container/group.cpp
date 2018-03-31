#include "group.h"

#include <QDebug>

Group::Group(QObject *parent) :
    BaseContainer(parent)
{
}

Group::Group(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    //qWarning() << "not implemented";
}
