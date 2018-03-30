#include "imagecollection.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

ImageCollection::ImageCollection(QObject *parent) :
    BaseContainer(parent)
{
}

ImageCollection::ImageCollection(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("images"))
        {
            Q_ASSERT(iter.value().isObject());
            for(auto imageValue : iter.value().toArray())
            {
                //TODO
                qWarning() << "images not implemented";
            }
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
