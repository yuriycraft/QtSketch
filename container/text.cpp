#include "text.h"

#include <QDebug>

Text::Text(QObject *parent) :
    BaseContainer(parent)
{
}

bool Text::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
