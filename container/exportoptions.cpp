#include "exportoptions.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include <QJsonDocument>

#include "containerfactory.h"

#include "exportformat.h"

ExportOptions::ExportOptions(QObject *parent) :
    BaseContainer(parent),
    m_layerOptions(0.),
    m_shouldTrim(false)
{
}

ExportOptions::ExportOptions(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_layerOptions(0.),
    m_shouldTrim(false)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("exportFormats"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto colorValue : iter.value().toArray())
            {
                Q_ASSERT(colorValue.isObject());
                m_exportFormats.append(ContainerFactory::createContainer<ExportFormat>(colorValue.toObject(), this));
            }
        }
        else if(iter.key() == QStringLiteral("includedLayerIds"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto includedLayerIdValue : iter.value().toArray())
            {
                //TODO
                qWarning() << "includedLayerIds not implemented";
            }
        }
        else if(iter.key() == QStringLiteral("layerOptions"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_layerOptions = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("shouldTrim"))
        {
            Q_ASSERT(iter.value().isBool());
            m_shouldTrim = iter.value().toBool();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
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
