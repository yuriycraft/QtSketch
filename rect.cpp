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

Rect::Rect(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_constrainProportions(false),
    m_height(0.),
    m_width(0.),
    m_x(0.),
    m_y(0.)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("constrainProportions"))
        {
            Q_ASSERT(iter.value().isBool());
            m_constrainProportions = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("height"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_height = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("width"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_width = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("x"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_x = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("y"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_y = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
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
