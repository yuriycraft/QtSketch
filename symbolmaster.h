#ifndef SYMBOLMASTER_H
#define SYMBOLMASTER_H

#include "basecontainer.h"

class QJsonObject;

class SymbolMaster : public BaseContainer
{
    Q_OBJECT

public:
    explicit SymbolMaster(QObject *parent = Q_NULLPTR);
    explicit SymbolMaster(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);
};

#endif // SYMBOLMASTER_H
