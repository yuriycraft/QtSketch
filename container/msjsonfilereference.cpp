#include "msjsonfilereference.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

MSJSONFileReference::MSJSONFileReference(QObject *parent) :
    BaseContainer(parent)
{
}

const QString &MSJSONFileReference::_ref() const
{
    return m__ref;
}

const QString &MSJSONFileReference::_ref_class() const
{
    return m__ref_class;
}

bool MSJSONFileReference::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("_ref"))
    {
        Q_ASSERT(value.isString());
        m__ref = value.toString();
        return true;
    }

    if(key == QStringLiteral("_ref_class"))
    {
        Q_ASSERT(value.isString());
        m__ref_class = value.toString();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
