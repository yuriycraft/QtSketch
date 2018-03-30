#include "msjsonfilereference.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

MSJSONFileReference::MSJSONFileReference(QObject *parent) :
    BaseContainer(parent)
{
}

MSJSONFileReference::MSJSONFileReference(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("_ref"))
        {
            Q_ASSERT(iter.value().isString());
            m__ref = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("_ref_class"))
        {
            Q_ASSERT(iter.value().isString());
            m__ref_class = iter.value().toString();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
