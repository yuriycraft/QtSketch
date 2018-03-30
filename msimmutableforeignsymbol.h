#ifndef MSIMMUTABLEFOREIGNSYMBOL_H
#define MSIMMUTABLEFOREIGNSYMBOL_H

#include "basecontainer.h"

class QJsonObject;

class MSImmutableForeignSymbol : public BaseContainer
{
    Q_OBJECT

public:
    explicit MSImmutableForeignSymbol(QObject *parent = Q_NULLPTR);
    explicit MSImmutableForeignSymbol(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);
};

#endif // MSIMMUTABLEFOREIGNSYMBOL_H
