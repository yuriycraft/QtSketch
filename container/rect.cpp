#include "rect.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

Rect::Rect(QObject *parent) :
    BaseContainer(parent),
    m_constrainProportions(false),
    m_height(0.),
    m_width(0.),
    m_x(0.),
    m_y(0.)
{
}

bool Rect::constrainProportions() const
{
    return m_constrainProportions;
}

double Rect::height() const
{
    return m_height;
}

double Rect::width() const
{
    return m_width;
}

double Rect::x() const
{
    return m_x;
}

double Rect::y() const
{
    return m_y;
}

bool Rect::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("constrainProportions"))
    {
        Q_ASSERT(value.isBool());
        m_constrainProportions = value.toBool();
        return true;
    }

    if(key == QStringLiteral("height"))
    {
        Q_ASSERT(value.isDouble());
        m_height = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("width"))
    {
        Q_ASSERT(value.isDouble());
        m_width = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("x"))
    {
        Q_ASSERT(value.isDouble());
        m_x = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("y"))
    {
        Q_ASSERT(value.isDouble());
        m_y = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
