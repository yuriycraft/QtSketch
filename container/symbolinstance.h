#ifndef SYMBOLINSTANCE_H
#define SYMBOLINSTANCE_H

#include "basecontainer.h"

class QJsonObject;

class SymbolInstance : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit SymbolInstance(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // SYMBOLINSTANCE_H
