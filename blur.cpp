#include "blur.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

Blur::Blur(QObject *parent) :
    BaseContainer(parent)
{
}

Blur::Blur(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("isEnabled"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isEnabled = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("center"))
        {
            Q_ASSERT(iter.value().isString());
            m_center = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("motionAngle"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_motionAngle = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("radius"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_radius = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("type"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_type = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
