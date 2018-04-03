#include "basecontainer.h"

#include <QDebug>
#include <QJsonObject>

const QHash<QJsonValue::Type, QString> BaseContainer::m_types {
    { QJsonValue::Null, QStringLiteral("Null") },
    { QJsonValue::Bool, QStringLiteral("Bool") },
    { QJsonValue::Double, QStringLiteral("Double") },
    { QJsonValue::String, QStringLiteral("String") },
    { QJsonValue::Array, QStringLiteral("Array") },
    { QJsonValue::Object, QStringLiteral("Object") },
    { QJsonValue::Undefined, QStringLiteral("Undefined") }
};

QHash<QString, int> BaseContainer::m_missing;

BaseContainer::BaseContainer(QObject *parent) :
    QObject(parent)
{
}

const QString &BaseContainer::do_objectID() const
{
    return m_do_objectID;
}

void BaseContainer::parseFromJson(const QJsonObject &jsonObj)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;

        if(!parseProperty(iter.key(), iter.value()))
        {
            QString key = QStringLiteral("%0::%1").arg(metaObject()->className(), iter.key());
            if(m_missing.contains(key))
                m_missing[key]++;
            else
                m_missing.insert(key, 1);

            //qWarning() << "unknown property" << metaObject()->className() << iter.key() << m_types.value(iter.value().type());
        }
    }
}

const QHash<QString, int> &BaseContainer::missing()
{
    return m_missing;
}

bool BaseContainer::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    return false;
}
