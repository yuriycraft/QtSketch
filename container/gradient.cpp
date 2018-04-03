#include "gradient.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "gradientstop.h"

Gradient::Gradient(QObject *parent) :
    BaseContainer(parent),
    m_elipseLength(0.),
    m_gradientType(0.),
    m_shouldSmoothenOpacity(false)
{
}

double Gradient::elipseLength() const
{
    return m_elipseLength;
}

const QString &Gradient::from() const
{
    return m_from;
}

double Gradient::gradientType() const
{
    return m_gradientType;
}

bool Gradient::shouldSmoothenOpacity() const
{
    return m_shouldSmoothenOpacity;
}

const QList<GradientStop *> &Gradient::stops() const
{
    return m_stops;
}

const QString &Gradient::to() const
{
    return m_to;
}

bool Gradient::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("elipseLength"))
    {
        Q_ASSERT(value.isDouble());
        m_elipseLength = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("from"))
    {
        Q_ASSERT(value.isString());
        m_from = value.toString();
        return true;
    }

    if(key == QStringLiteral("gradientType"))
    {
        Q_ASSERT(value.isDouble());
        m_gradientType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("shouldSmoothenOpacity"))
    {
        Q_ASSERT(value.isBool());
        m_shouldSmoothenOpacity = value.toBool();
        return true;
    }

    if(key == QStringLiteral("stops"))
    {
        Q_ASSERT(value.isArray());
        for(auto gradientStopValue : value.toArray())
        {
            Q_ASSERT(gradientStopValue.isObject());
            m_stops.append(ContainerFactory::createContainer<GradientStop>(gradientStopValue.toObject(), this));
        }
        return true;
    }

    if(key == QStringLiteral("to"))
    {
        Q_ASSERT(value.isString());
        m_to = value.toString();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
