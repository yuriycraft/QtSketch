#include "border.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "color.h"

Border::Border(QObject *parent) :
    BaseContainer(parent),
    m_color(Q_NULLPTR),
    m_fillType(FillType::FlatColor),
    m_isEnabled(false),
    m_position(Position::Inside),
    m_thickness(0.)
{
}

Color *Border::color() const
{
    return m_color;
}

Border::FillType Border::fillType() const
{
    return m_fillType;
}

bool Border::isEnabled() const
{
    return m_isEnabled;
}

Border::Position Border::position() const
{
    return m_position;
}

double Border::thickness() const
{
    return m_thickness;
}

bool Border::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("color"))
    {
        Q_ASSERT(value.isObject());
        m_color = ContainerFactory::createContainer<Color>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("fillType"))
    {
        Q_ASSERT(value.isDouble());
        m_fillType = FillType(int(value.toDouble()));
        return true;
    }

    if(key == QStringLiteral("isEnabled"))
    {
        Q_ASSERT(value.isBool());
        m_isEnabled = value.toBool();
        return true;
    }

    if(key == QStringLiteral("position"))
    {
        Q_ASSERT(value.isDouble());
        m_position = Position(int(value.toDouble()));
        return true;
    }

    if(key == QStringLiteral("thickness"))
    {
        Q_ASSERT(value.isDouble());
        m_thickness = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
