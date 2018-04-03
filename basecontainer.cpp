#include "basecontainer.h"

#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

QHash<QJsonValue::Type, QString> types {
    { QJsonValue::Null, QStringLiteral("Null") },
    { QJsonValue::Bool, QStringLiteral("Bool") },
    { QJsonValue::Double, QStringLiteral("Double") },
    { QJsonValue::String, QStringLiteral("String") },
    { QJsonValue::Array, QStringLiteral("Array") },
    { QJsonValue::Object, QStringLiteral("Object") },
    { QJsonValue::Undefined, QStringLiteral("Undefined") }
};

BaseContainer::BaseContainer(const QJsonObject &jsonObj, QObject *parent) :
    QObject(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;

        if(!parseProperty(iter.key(), iter.value()))
            qWarning() << "unknown property" << iter.key() << types.value(iter.value().type());
    }
}

bool BaseContainer::parseProperty(const QString &key, const QJsonValue &value)
{
    Q_UNUSED(key)
    Q_UNUSED(value)

    return false;
}
