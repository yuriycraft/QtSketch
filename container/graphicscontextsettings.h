#ifndef GRAPHICSCONTEXTSETTINGS_H
#define GRAPHICSCONTEXTSETTINGS_H

#include "basecontainer.h"

class QJsonObject;

class GraphicsContextSettings : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double blendMode READ blendMode CONSTANT)
    Q_PROPERTY(double opacity READ opacity CONSTANT)

public:
    Q_INVOKABLE explicit GraphicsContextSettings(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit GraphicsContextSettings(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    double blendMode() const;
    double opacity() const;

private:
    double m_blendMode;
    double m_opacity;
};

#endif // GRAPHICSCONTEXTSETTINGS_H
