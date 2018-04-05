#include "artboard.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "color.h"

Artboard::Artboard(QObject *parent) :
    Group(parent),
    m_backgroundColor(Q_NULLPTR),
    m_hasBackgroundColor(false)
{
}

Color *Artboard::backgroundColor() const
{
    return m_backgroundColor;
}

bool Artboard::hasBackgroundColor() const
{
    return m_hasBackgroundColor;
}

bool Artboard::parseProperty(const QString &key, const QJsonValue &value)
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

    return Group::parseProperty(key, value);
}
