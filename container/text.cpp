#include "text.h"

#include <QDebug>

Text::Text(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

bool Text::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
