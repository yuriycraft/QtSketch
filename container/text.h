#pragma once

#include "layer.h"

class QJsonObject;

class Text : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Text(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};
