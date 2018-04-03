#ifndef SYMBOLCONTAINER_H
#define SYMBOLCONTAINER_H

#include "basecontainer.h"

class QJsonObject;

class SymbolContainer : public BaseContainer
{
    Q_OBJECT
    //TODO objects

public:
    Q_INVOKABLE explicit SymbolContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    //TODO objects

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    //TODO objects
};

#endif // SYMBOLCONTAINER_H
