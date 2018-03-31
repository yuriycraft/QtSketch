#ifndef SYMBOLCONTAINER_H
#define SYMBOLCONTAINER_H

#include "basecontainer.h"

class QJsonObject;

class SymbolContainer : public BaseContainer
{
    Q_OBJECT

public:
    explicit SymbolContainer(QObject *parent = Q_NULLPTR);
    explicit SymbolContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    //TODO objects

private:
    //TODO objects
};

#endif // SYMBOLCONTAINER_H
