#include "textstyle.h"

#include <QDebug>

TextStyle::TextStyle(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

bool TextStyle::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
