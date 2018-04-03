#include "bitmap.h"

Bitmap::Bitmap(QObject *parent) :
    Layer(parent)
{
}

bool Bitmap::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
