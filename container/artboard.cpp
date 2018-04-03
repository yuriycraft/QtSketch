#include "artboard.h"

Artboard::Artboard(QObject *parent) :
    Group(parent)
{
}

bool Artboard::parseProperty(const QString &key, const QJsonValue &value)
{
    return Group::parseProperty(key, value);
}
