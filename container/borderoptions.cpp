#include "borderoptions.h"

#include <QJsonValue>
#include <QJsonArray>

BorderOptions::BorderOptions(QObject *parent) :
    BaseContainer(parent)
{
}

const QString &BorderOptions::do_objectID() const
{
    return m_do_objectID;
}

const QList<double> &BorderOptions::dashPattern() const
{
    return m_dashPattern;
}

bool BorderOptions::isEnabled() const
{
    return m_isEnabled;
}

double BorderOptions::lineCapStyle() const
{
    return m_lineCapStyle;
}

double BorderOptions::lineJoinStyle() const
{
    return m_lineJoinStyle;
}

bool BorderOptions::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("dashPattern"))
    {
        Q_ASSERT(value.isArray());
        for(auto dashPatternValue : value.toArray())
        {
            Q_ASSERT(dashPatternValue.isDouble());
            m_dashPattern.append(dashPatternValue.toDouble());
        }
        return true;
    }

    if(key == QStringLiteral("isEnabled"))
    {
        Q_ASSERT(value.isBool());
        m_isEnabled = value.toBool();
        return true;
    }

    if(key == QStringLiteral("lineCapStyle"))
    {
        Q_ASSERT(value.isDouble());
        m_lineCapStyle = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("lineJoinStyle"))
    {
        Q_ASSERT(value.isDouble());
        m_lineJoinStyle = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
