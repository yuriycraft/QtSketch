#include "symbolinstance.h"

#include <QDebug>

SymbolInstance::SymbolInstance(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

bool SymbolInstance::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
