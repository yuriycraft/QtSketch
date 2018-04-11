#pragma once

#include "basecontainer.h"

class QJsonObject;

class GraphicsContextSettings : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double blendMode READ blendMode CONSTANT)
    Q_PROPERTY(double opacity READ opacity CONSTANT)

public:
    Q_INVOKABLE explicit GraphicsContextSettings(QObject *parent = Q_NULLPTR);

    double blendMode() const;
    double opacity() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    double m_blendMode;
    double m_opacity;
};
