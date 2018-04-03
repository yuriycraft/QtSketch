#include "sharedtextstylecontainer.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "sharedstyle.h"

SharedTextStyleContainer::SharedTextStyleContainer(QObject *parent) :
    BaseContainer(parent)
{
}

const QList<SharedStyle *> &SharedTextStyleContainer::objects() const
{
    return m_objects;
}

bool SharedTextStyleContainer::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("objects"))
    {
        Q_ASSERT(value.isArray());
        for(auto objectValue : value.toArray())
        {
            Q_ASSERT(objectValue.isObject());
            m_objects.append(ContainerFactory::createContainer<SharedStyle>(objectValue.toObject(), this));
        }
    }

    return BaseContainer::parseProperty(key, value);
}
