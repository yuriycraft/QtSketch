#include "textstyle.h"

#include <QDebug>

TextStyle::TextStyle(QObject *parent) :
    BaseContainer(parent)
{
}

bool TextStyle::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
