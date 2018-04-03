#include "shapegroup.h"

ShapeGroup::ShapeGroup(QObject *parent) :
    Group(parent)
{
}

bool ShapeGroup::parseProperty(const QString &key, const QJsonValue &value)
{
    return Group::parseProperty(key, value);
}
