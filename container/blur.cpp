#include "blur.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

Blur::Blur(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

bool Blur::isEnabled() const
{
    return m_isEnabled;
}

const QString &Blur::center() const
{
    return m_center;
}

double Blur::motionAngle() const
{
    return m_motionAngle;
}

double Blur::radius() const
{
    return m_radius;
}

double Blur::type() const
{
    return m_type;
}

bool Blur::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("isEnabled"))
    {
        Q_ASSERT(value.isBool());
        m_isEnabled = value.toBool();
        return true;
    }

    if(key == QStringLiteral("center"))
    {
        Q_ASSERT(value.isString());
        m_center = value.toString();
        return true;
    }

    if(key == QStringLiteral("motionAngle"))
    {
        Q_ASSERT(value.isDouble());
        m_motionAngle = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("radius"))
    {
        Q_ASSERT(value.isDouble());
        m_radius = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("type"))
    {
        Q_ASSERT(value.isDouble());
        m_type = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
