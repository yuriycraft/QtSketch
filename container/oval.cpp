#include "oval.h"

Oval::Oval(QObject *parent) :
    Layer(parent)
{
}

bool Oval::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
