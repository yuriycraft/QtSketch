#include "gradientstop.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "color.h"

GradientStop::GradientStop(QObject *parent) :
    BaseContainer(parent)
{
}

Color *GradientStop::color() const
{
    return m_color;
}

double GradientStop::position() const
{
    return m_position;
}

bool GradientStop::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("color"))
    {
        Q_ASSERT(value.isObject());
        m_color = ContainerFactory::createContainer<Color>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("position"))
    {
        Q_ASSERT(value.isDouble());
        m_position = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
