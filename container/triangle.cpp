#include "triangle.h"

Triangle::Triangle(QObject *parent) :
    Layer(parent)
{
}

bool Triangle::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
