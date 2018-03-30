#include "sharedstyle.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

#include "utils.h"

#include "style.h"

SharedStyle::SharedStyle(QObject *parent) :
    BaseContainer(parent)
{
}

SharedStyle::SharedStyle(const QJsonObject &jsonObj, QObject *parent) :
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
        else if(iter.key() == QStringLiteral("name"))
        {
            Q_ASSERT(iter.value().isString());
            m_name = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("value"))
        {
            Q_ASSERT(iter.value().isObject());
            m_value = getContainer<Style>(iter.value().toObject());
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
