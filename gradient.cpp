#include "gradient.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

#include "gradientstop.h"

Gradient::Gradient(QObject *parent) :
    BaseContainer(parent),
    m_elipseLength(0.),
    m_gradientType(0.),
    m_shouldSmoothenOpacity(false)
{
}

Gradient::Gradient(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_elipseLength(0.),
    m_gradientType(0.),
    m_shouldSmoothenOpacity(false)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("elipseLength"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_elipseLength = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("from"))
        {
            Q_ASSERT(iter.value().isString());
            m_from = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("gradientType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_gradientType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("shouldSmoothenOpacity"))
        {
            Q_ASSERT(iter.value().isBool());
            m_shouldSmoothenOpacity = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("stops"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto gradientStopValue : iter.value().toArray())
            {
                Q_ASSERT(gradientStopValue.isObject());
                m_stops.append(createContainer<GradientStop>(gradientStopValue.toObject(), this));
            }
        }
        else if(iter.key() == QStringLiteral("to"))
        {
            Q_ASSERT(iter.value().isString());
            m_to = iter.value().toString();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
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
