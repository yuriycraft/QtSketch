#include "border.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

#include "utils.h"

#include "color.h"

Border::Border(QObject *parent) :
    BaseContainer(parent),
    m_color(Q_NULLPTR),
    m_fillType(0.),
    m_isEnabled(false),
    m_position(0.),
    m_thickness(0.)
{
}

Border::Border(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_color(Q_NULLPTR),
    m_fillType(0.),
    m_isEnabled(false),
    m_position(0.),
    m_thickness(0.)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("color"))
        {
            Q_ASSERT(iter.value().isObject());
            m_color = createContainer<Color>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("fillType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_fillType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("isEnabled"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isEnabled = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("position"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_position = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("thickness"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_thickness = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

const Color *Border::color() const
{
    return m_color;
}

double Border::fillType() const
{
    return m_fillType;
}

bool Border::isEnabled() const
{
    return m_isEnabled;
}

double Border::position() const
{
    return m_position;
}

double Border::thickness() const
{
    return m_thickness;
}
