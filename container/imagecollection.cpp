#include "imagecollection.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

ImageCollection::ImageCollection(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

bool ImageCollection::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("images"))
    {
        Q_ASSERT(value.isObject());
        for(auto imageValue : value.toArray())
        {
            //TODO
            qWarning() << "images not implemented";
        }
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
