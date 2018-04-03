#include "artboard.h"

#include <QDebug>

Artboard::Artboard(QObject *parent) :
    BaseContainer(parent)
{
}

bool Artboard::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
