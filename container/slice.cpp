#include "slice.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "color.h"

Slice::Slice(QObject *parent) :
    Layer(parent),
    m_backgroundColor(Q_NULLPTR),
    m_hasBackgroundColor(false)
{
}

Color *Slice::backgroundColor() const
{
    return m_backgroundColor;
}

bool Slice::hasBackgroundColor() const
{
    return m_hasBackgroundColor;
}

bool Slice::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("backgroundColor"))
    {
        Q_ASSERT(value.isObject());
        m_backgroundColor = ContainerFactory::createContainer<Color>(value.toObject());
        return true;
    }

    if(key == QStringLiteral("hasBackgroundColor"))
    {
        Q_ASSERT(value.isBool());
        m_hasBackgroundColor = value.toBool();
        return true;
    }

    return Layer::parseProperty(key, value);
}
