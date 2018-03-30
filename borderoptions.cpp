#include "borderoptions.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

BorderOptions::BorderOptions(QObject *parent) :
    BaseContainer(parent)
{
}

BorderOptions::BorderOptions(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("dashPattern"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto dashPatternValue : iter.value().toArray())
            {
                Q_ASSERT(dashPatternValue.isDouble());
                m_dashPattern.append(dashPatternValue.toDouble());
            }
        }
        else if(iter.key() == QStringLiteral("isEnabled"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isEnabled = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("lineCapStyle"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_lineCapStyle = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("lineJoinStyle"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_lineJoinStyle = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
