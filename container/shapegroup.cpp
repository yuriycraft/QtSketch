#include "shapegroup.h"

#include <QDebug>

ShapeGroup::ShapeGroup(QObject *parent) :
    BaseContainer(parent)
{
}

ShapeGroup::ShapeGroup(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
