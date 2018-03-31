#ifndef SYMBOLINSTANCE_H
#define SYMBOLINSTANCE_H

#include "basecontainer.h"

class QJsonObject;

class SymbolInstance : public BaseContainer
{
    Q_OBJECT

public:
    explicit SymbolInstance(QObject *parent = Q_NULLPTR);
    explicit SymbolInstance(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // SYMBOLINSTANCE_H
