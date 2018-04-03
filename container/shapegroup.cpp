#include "shapegroup.h"

ShapeGroup::ShapeGroup(QObject *parent) :
    Layer(parent)
{
}

bool ShapeGroup::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
