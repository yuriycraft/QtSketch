#include "sharedstyle.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "style.h"

SharedStyle::SharedStyle(QObject *parent) :
    BaseContainer(parent)
{
}

const QString &SharedStyle::do_objectID() const
{
    return m_do_objectID;
}

const QString &SharedStyle::name() const
{
    return m_name;
}

Style *SharedStyle::value() const
{
    return m_value;
}

bool SharedStyle::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("name"))
    {
        Q_ASSERT(value.isString());
        m_name = value.toString();
        return true;
    }

    if(key == QStringLiteral("value"))
    {
        Q_ASSERT(value.isObject());
        m_value = ContainerFactory::createContainer<Style>(value.toObject(), this);
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
