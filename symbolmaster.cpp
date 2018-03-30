#include "symbolmaster.h"

#include <QDebug>

SymbolMaster::SymbolMaster(QObject *parent) :
    BaseContainer(parent)
{
}

SymbolMaster::SymbolMaster(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
