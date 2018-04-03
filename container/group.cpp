#include "group.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include "containerfactory.h"

#include "layer.h"

Group::Group(QObject *parent) :
    Layer(parent)
{
}

const QList<Layer *> &Group::layers() const
{
    return m_layers;
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
        qWarning() << "flow not implemented";
        return true;
    }

    return Layer::parseProperty(key, value);
}
