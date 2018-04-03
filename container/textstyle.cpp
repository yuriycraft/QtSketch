#include "textstyle.h"

TextStyle::TextStyle(QObject *parent) :
    BaseContainer(parent)
{
}

bool TextStyle::parseProperty(const QString &key, const QJsonValue &value)
{
    return BaseContainer::parseProperty(key, value);
}
