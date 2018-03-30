#include "color.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

Color::Color(QObject *parent) :
    BaseContainer(parent),
    m_alpha(0.),
    m_blue(0.),
    m_green(0.),
    m_red(0.)
{
}

Color::Color(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_alpha(0.),
    m_blue(0.),
    m_green(0.),
    m_red(0.)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("alpha"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_alpha = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("blue"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_blue = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("green"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_green = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("red"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_red = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
