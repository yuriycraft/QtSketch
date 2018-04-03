#include "exportoptions.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <QJsonDocument>

#include "containerfactory.h"

#include "exportformat.h"

ExportOptions::ExportOptions(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent),
    m_layerOptions(0.),
    m_shouldTrim(false)
{
}

const QList<ExportFormat *> &ExportOptions::exportFormats() const
{
    return m_exportFormats;
}

double ExportOptions::layerOptions() const
{
    return m_layerOptions;
}

bool ExportOptions::shouldTrim() const
{
    return m_shouldTrim;
}

bool ExportOptions::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("exportFormats"))
    {
        Q_ASSERT(value.isArray());
        for(auto colorValue : value.toArray())
        {
            Q_ASSERT(colorValue.isObject());
            m_exportFormats.append(ContainerFactory::createContainer<ExportFormat>(colorValue.toObject(), this));
        }
        return true;
    }

    if(key == QStringLiteral("includedLayerIds"))
    {
        Q_ASSERT(value.isArray());
        for(auto includedLayerIdValue : value.toArray())
        {
            //TODO
            qWarning() << "includedLayerIds not implemented";
        }
        return true;
    }

    if(key == QStringLiteral("layerOptions"))
    {
        Q_ASSERT(value.isDouble());
        m_layerOptions = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("shouldTrim"))
    {
        Q_ASSERT(value.isBool());
        m_shouldTrim = value.toBool();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
