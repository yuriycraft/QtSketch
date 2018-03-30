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

GraphicsContextSettings::GraphicsContextSettings(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_blendMode(0.),
    m_opacity(0.)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("blendMode"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_blendMode = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("opacity"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_opacity = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

double GraphicsContextSettings::blendMode() const
{
    return m_blendMode;
}

double GraphicsContextSettings::opacity() const
{
    return m_opacity;
}
