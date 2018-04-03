#include "shapegroup.h"

ShapeGroup::ShapeGroup(QObject *parent) :
    BaseContainer(parent)
{
}

bool ShapeGroup::parseProperty(const QString &key, const QJsonValue &value)
{
    return BaseContainer::parseProperty(key, value);
}
