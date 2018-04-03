#include "slice.h"

Slice::Slice(QObject *parent) :
    Layer(parent)
{
}

bool Slice::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
