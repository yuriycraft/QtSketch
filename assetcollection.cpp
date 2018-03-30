#include "assetcollection.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

#include "color.h"
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
            for(auto colorValue : iter.value().toArray())
            {
                Q_ASSERT(colorValue.isObject());
                m_colors.append(createContainer<Color>(colorValue.toObject(), this));
            }
        }
        else if(iter.key() == QStringLiteral("gradients"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto gradientValue : iter.value().toArray())
            {
                //TODO
                qWarning() << "gradients not implemented";
            }
        }
        else if(iter.key() == QStringLiteral("imageCollection"))
        {
            Q_ASSERT(iter.value().isObject());
            m_imageCollection = createContainer<ImageCollection>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("images"))
        {
            Q_ASSERT(iter.value().isArray());
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
