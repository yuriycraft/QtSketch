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

SharedStyleContainer::SharedStyleContainer(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("do_objectID"))
        {
            Q_ASSERT(iter.value().isString());
            m_do_objectID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("objects"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto objectValue : iter.value().toArray())
            {
                Q_ASSERT(objectValue.isObject());
                m_objects.append(ContainerFactory::createContainer<SharedStyle>(objectValue.toObject(), this));
            }
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

const QString &SharedStyleContainer::do_objectID() const
{
    return m_do_objectID;
}

const QList<SharedStyle *> &SharedStyleContainer::objects() const
{
    return m_objects;
}
