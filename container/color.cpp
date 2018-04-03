#include "color.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

Color::Color(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent),
    m_alpha(0.),
    m_blue(0.),
    m_green(0.),
    m_red(0.)
{
}

double Color::alpha() const
{
    return m_alpha;
}

double Color::blue() const
{
    return m_blue;
}

double Color::green() const
{
    return m_green;
}

double Color::red() const
{
    return m_red;
}

bool Color::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("alpha"))
    {
        Q_ASSERT(value.isDouble());
        m_alpha = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("blue"))
    {
        Q_ASSERT(value.isDouble());
        m_blue = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("green"))
    {
        Q_ASSERT(value.isDouble());
        m_green = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("red"))
    {
        Q_ASSERT(value.isDouble());
        m_red = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
