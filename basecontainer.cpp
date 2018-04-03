#include "basecontainer.h"

#include <QJsonObject>
#include <QDebug>

const QHash<QJsonValue::Type, QString> BaseContainer::m_types {
    { QJsonValue::Null, QStringLiteral("Null") },
    { QJsonValue::Bool, QStringLiteral("Bool") },
    { QJsonValue::Double, QStringLiteral("Double") },
    { QJsonValue::String, QStringLiteral("String") },
    { QJsonValue::Array, QStringLiteral("Array") },
    { QJsonValue::Object, QStringLiteral("Object") },
    { QJsonValue::Undefined, QStringLiteral("Undefined") }
};

BaseContainer::BaseContainer(QObject *parent) :
    QObject(parent)
{
}

void BaseContainer::parseFromJson(const QJsonObject &jsonObj)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;

        if(!parseProperty(iter.key(), iter.value()))
            qWarning() << "unknown property" << jsonObj.value(QStringLiteral("_class")).toString() << iter.key() << m_types.value(iter.value().type());
    }
}

bool BaseContainer::parseProperty(const QString &key, const QJsonValue &value)
{
    Q_UNUSED(key)
    Q_UNUSED(value)

    return false;
}
