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

SharedTextStyleContainer::SharedTextStyleContainer(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
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

const QList<SharedStyle *> &SharedTextStyleContainer::objects() const
{
    return m_objects;
}
