#include "graphicscontextsettings.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

GraphicsContextSettings::GraphicsContextSettings(QObject *parent) :
    BaseContainer(parent),
    m_blendMode(0.),
    m_opacity(0.)
{
}

double GraphicsContextSettings::blendMode() const
{
    return m_blendMode;
}

double GraphicsContextSettings::opacity() const
{
    return m_opacity;
}

bool GraphicsContextSettings::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("blendMode"))
    {
        Q_ASSERT(value.isDouble());
        m_blendMode = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("opacity"))
    {
        Q_ASSERT(value.isDouble());
        m_opacity = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
