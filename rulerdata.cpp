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

RulerData::RulerData(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_base(0.)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("base"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_base = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("guides"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto guideValue : iter.value().toArray())
            {
                //TODO
                qWarning() << "guides not implemented";
            }
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
