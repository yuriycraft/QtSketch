#include "text.h"

Text::Text(QObject *parent) :
    Layer(parent)
{
}

bool Text::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
