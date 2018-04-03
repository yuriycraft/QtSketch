#ifndef SYMBOLINSTANCE_H
#define SYMBOLINSTANCE_H

#include "layer.h"

class QJsonObject;

class SymbolInstance : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit SymbolInstance(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // SYMBOLINSTANCE_H
