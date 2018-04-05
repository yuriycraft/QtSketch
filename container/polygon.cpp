#include "polygon.h"

Polygon::Polygon(QObject *parent) :
    BaseContainer(parent)
{
}

bool Polygon::parseProperty(const QString &key, const QJsonValue &value)
{
    return BaseContainer::parseProperty(key, value);
}
