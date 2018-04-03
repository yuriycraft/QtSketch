#include "rectangle.h"

Rectangle::Rectangle(QObject *parent) :
    Layer(parent)
{
}

bool Rectangle::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
