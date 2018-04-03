#include "symbolinstance.h"

#include <QDebug>

SymbolInstance::SymbolInstance(QObject *parent) :
    BaseContainer(parent)
{
}

bool SymbolInstance::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
