#include "group.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "layer.h"

Group::Group(QObject *parent) :
    Layer(parent),
    m_hasClickThrough(false)
{
}

const QList<Layer *> &Group::layers() const
{
    return m_layers;
}

bool Group::hasClickThrough() const
{
    return m_hasClickThrough;
}

bool Group::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("layers"))
    {
        Q_ASSERT(value.isArray());
        for(auto layerValue : value.toArray())
        {
            Q_ASSERT(layerValue.isObject());
            m_layers.append(ContainerFactory::createContainer<Layer>(layerValue.toObject()));
        }
        return true;
    }

    if(key == QStringLiteral("flow"))
    {
        Q_ASSERT(value.isObject());
        //qWarning() << "flow not implemented";
        return true;
    }

    if(key == QStringLiteral("hasClickThrough"))
    {
        Q_ASSERT(value.isBool());
        m_hasClickThrough = value.toBool();
        return true;
    }

    return Layer::parseProperty(key, value);
}
