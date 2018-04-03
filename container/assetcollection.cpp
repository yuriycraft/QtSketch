#include "assetcollection.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "color.h"
#include "imagecollection.h"

AssetCollection::AssetCollection(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent),
    m_imageCollection(Q_NULLPTR)
{
}

const QList<Color *> &AssetCollection::colors() const
{
    return m_colors;
}

ImageCollection *AssetCollection::imageCollection() const
{
    return m_imageCollection;
}

bool AssetCollection::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("colors"))
    {
        Q_ASSERT(value.isArray());
        for(auto colorValue : value.toArray())
        {
            Q_ASSERT(colorValue.isObject());
            m_colors.append(ContainerFactory::createContainer<Color>(colorValue.toObject(), this));
        }
        return true;
    }

    if(key == QStringLiteral("gradients"))
    {
        Q_ASSERT(value.isArray());
        for(auto gradientValue : value.toArray())
        {
            //TODO
            qWarning() << "gradients not implemented";
        }
        return true;
    }

    if(key == QStringLiteral("imageCollection"))
    {
        Q_ASSERT(value.isObject());
        m_imageCollection = ContainerFactory::createContainer<ImageCollection>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("images"))
    {
        Q_ASSERT(value.isArray());
        for(auto imageValue : value.toArray())
        {
            //TODO
            qWarning() << "images not implemented";
        }
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
