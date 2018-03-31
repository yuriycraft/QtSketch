#ifndef GRAPHICSCONTEXTSETTINGS_H
#define GRAPHICSCONTEXTSETTINGS_H

#include "basecontainer.h"

class QJsonObject;

class GraphicsContextSettings : public BaseContainer
{
    Q_OBJECT

public:
    explicit GraphicsContextSettings(QObject *parent = Q_NULLPTR);
    explicit GraphicsContextSettings(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    double blendMode() const;
    double opacity() const;

private:
    double m_blendMode;
    double m_opacity;
};

#endif // GRAPHICSCONTEXTSETTINGS_H
