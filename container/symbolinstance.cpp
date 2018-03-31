#include "symbolinstance.h"

#include <QDebug>

SymbolInstance::SymbolInstance(QObject *parent) :
    BaseContainer(parent)
{
}

SymbolInstance::SymbolInstance(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
