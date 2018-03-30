#include "assetcollection.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

#include "imagecollection.h"

AssetCollection::AssetCollection(QObject *parent) :
    BaseContainer(parent),
    m_imageCollection(Q_NULLPTR)
{
}

AssetCollection::AssetCollection(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_imageCollection(Q_NULLPTR)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("colors"))
        {
            Q_ASSERT(iter.value().isArray());
            //TODO
            qWarning() << "colors not implemented";
        }
        else if(iter.key() == QStringLiteral("gradients"))
        {
            Q_ASSERT(iter.value().isArray());
            //TODO
            qWarning() << "gradients not implemented";
        }
        else if(iter.key() == QStringLiteral("imageCollection"))
        {
            Q_ASSERT(iter.value().isObject());
            m_imageCollection = getContainer<ImageCollection>(iter.value().toObject());
        }
        else if(iter.key() == QStringLiteral("images"))
        {
            Q_ASSERT(iter.value().isArray());
            //TODO
            qWarning() << "images not implemented";
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
