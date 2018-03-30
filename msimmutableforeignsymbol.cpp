#include "msimmutableforeignsymbol.h"

#include <QDebug>

MSImmutableForeignSymbol::MSImmutableForeignSymbol(QObject *parent) :
    BaseContainer(parent)
{
}

MSImmutableForeignSymbol::MSImmutableForeignSymbol(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
