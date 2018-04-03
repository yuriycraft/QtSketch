#include "shapepath.h"

ShapePath::ShapePath(QObject *parent) :
    Layer(parent)
{
}

bool ShapePath::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
