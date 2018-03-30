#include "msimmutableforeignsymbol.h"

MSImmutableForeignSymbol::MSImmutableForeignSymbol(QObject *parent) :
    BaseContainer(parent)
{
}

MSImmutableForeignSymbol::MSImmutableForeignSymbol(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
}
