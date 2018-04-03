#include "symbolinstance.h"

SymbolInstance::SymbolInstance(QObject *parent) :
    Layer(parent)
{
}

bool SymbolInstance::parseProperty(const QString &key, const QJsonValue &value)
{
    return Layer::parseProperty(key, value);
}
