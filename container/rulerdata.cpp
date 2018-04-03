#include "rulerdata.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

RulerData::RulerData(QObject *parent) :
    BaseContainer(parent),
    m_base(0.)
{
}

double RulerData::base() const
{
    return m_base;
}

bool RulerData::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("base"))
    {
        Q_ASSERT(value.isDouble());
        m_base = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("guides"))
    {
        Q_ASSERT(value.isArray());
        for(auto guideValue : value.toArray())
        {
            //TODO
            qWarning() << "guides not implemented";
        }
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
