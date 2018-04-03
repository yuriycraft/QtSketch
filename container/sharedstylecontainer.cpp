#include "sharedstylecontainer.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "sharedstyle.h"

SharedStyleContainer::SharedStyleContainer(QObject *parent) :
    BaseContainer(parent)
{
}

const QString &SharedStyleContainer::do_objectID() const
{
    return m_do_objectID;
}

const QList<SharedStyle *> &SharedStyleContainer::objects() const
{
    return m_objects;
}

bool SharedStyleContainer::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("objects"))
    {
        Q_ASSERT(value.isArray());
        for(auto objectValue : value.toArray())
        {
            Q_ASSERT(objectValue.isObject());
            m_objects.append(ContainerFactory::createContainer<SharedStyle>(objectValue.toObject(), this));
        }
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
