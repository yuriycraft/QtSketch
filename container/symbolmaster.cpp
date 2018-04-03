#include "symbolmaster.h"

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "color.h"
#include "exportoptions.h"
#include "rect.h"
#include "rulerdata.h"
#include "group.h"
#include "style.h"

SymbolMaster::SymbolMaster(QObject *parent) :
    Artboard(parent),
    m_backgroundColor(Q_NULLPTR),
    m_changeIdentifier(0.),
    m_exportOptions(Q_NULLPTR),
    m_hasBackgroundColor(false),
    m_hasClickThrough(false),
    m_horizontalRulerData(Q_NULLPTR),
    m_includeBackgroundColorInExport(false),
    m_includeBackgroundColorInInstance(false),
    m_includeInCloudUpload(false),
    m_isFlowHome(false),
    m_isLocked(false),
    m_layerListExpandedType(0.),
    m_nameIsFixed(false),
    m_resizesContent(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_shouldBreakMaskChain(false),
    m_verticalRulerData(Q_NULLPTR)
{
}

Color *SymbolMaster::backgroundColor() const
{
    return m_backgroundColor;
}

double SymbolMaster::changeIdentifier() const
{
    return m_changeIdentifier;
}

ExportOptions *SymbolMaster::exportOptions() const
{
    return m_exportOptions;
}

bool SymbolMaster::hasBackgroundColor() const
{
    return m_hasBackgroundColor;
}

bool SymbolMaster::hasClickThrough() const
{
    return m_hasClickThrough;
}

RulerData *SymbolMaster::horizontalRulerData() const
{
    return m_horizontalRulerData;
}

bool SymbolMaster::includeBackgroundColorInExport() const
{
    return m_includeBackgroundColorInExport;
}

bool SymbolMaster::includeBackgroundColorInInstance() const
{
    return m_includeBackgroundColorInInstance;
}

bool SymbolMaster::includeInCloudUpload() const
{
    return m_includeInCloudUpload;
}

bool SymbolMaster::isFlowHome() const
{
    return m_isFlowHome;
}

bool SymbolMaster::isLocked() const
{
    return m_isLocked;
}

double SymbolMaster::layerListExpandedType() const
{
    return m_layerListExpandedType;
}

bool SymbolMaster::nameIsFixed() const
{
    return m_nameIsFixed;
}

bool SymbolMaster::resizesContent() const
{
    return m_resizesContent;
}

double SymbolMaster::resizingConstraint() const
{
    return m_resizingConstraint;
}

double SymbolMaster::resizingType() const
{
    return m_resizingType;
}

bool SymbolMaster::shouldBreakMaskChain() const
{
    return m_shouldBreakMaskChain;
}

const QString &SymbolMaster::symbolID() const
{
    return m_symbolID;
}

RulerData *SymbolMaster::verticalRulerData() const
{
    return m_verticalRulerData;
}

bool SymbolMaster::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("backgroundColor"))
    {
        Q_ASSERT(value.isObject());
        m_backgroundColor = ContainerFactory::createContainer<Color>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("changeIdentifier"))
    {
        Q_ASSERT(value.isDouble());
        m_changeIdentifier = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("exportOptions"))
    {
        Q_ASSERT(value.isObject());
        m_exportOptions = ContainerFactory::createContainer<ExportOptions>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("hasBackgroundColor"))
    {
        Q_ASSERT(value.isBool());
        m_hasBackgroundColor = value.toBool();
        return true;
    }

    if(key == QStringLiteral("hasClickThrough"))
    {
        Q_ASSERT(value.isBool());
        m_hasClickThrough = value.toBool();
        return true;
    }

    if(key == QStringLiteral("horizontalRulerData"))
    {
        Q_ASSERT(value.isObject());
        m_horizontalRulerData = ContainerFactory::createContainer<RulerData>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("includeBackgroundColorInExport"))
    {
        Q_ASSERT(value.isBool());
        m_includeBackgroundColorInExport = value.toBool();
        return true;
    }

    if(key == QStringLiteral("includeBackgroundColorInInstance"))
    {
        Q_ASSERT(value.isBool());
        m_includeBackgroundColorInInstance = value.toBool();
        return true;
    }

    if(key == QStringLiteral("includeInCloudUpload"))
    {
        Q_ASSERT(value.isBool());
        m_includeInCloudUpload = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isFlowHome"))
    {
        Q_ASSERT(value.isBool());
        m_isFlowHome = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isLocked"))
    {
        Q_ASSERT(value.isBool());
        m_isLocked = value.toBool();
        return true;
    }

    if(key == QStringLiteral("layerListExpandedType"))
    {
        Q_ASSERT(value.isDouble());
        m_layerListExpandedType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("nameIsFixed"))
    {
        Q_ASSERT(value.isBool());
        m_nameIsFixed = value.toBool();
        return true;
    }

    if(key == QStringLiteral("resizesContent"))
    {
        Q_ASSERT(value.isBool());
        m_resizesContent = value.toBool();
        return true;
    }

    if(key == QStringLiteral("resizingConstraint"))
    {
        Q_ASSERT(value.isDouble());
        m_resizingConstraint = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("resizingType"))
    {
        Q_ASSERT(value.isDouble());
        m_resizingType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("shouldBreakMaskChain"))
    {
        Q_ASSERT(value.isBool());
        m_shouldBreakMaskChain = value.toBool();
        return true;
    }

    if(key == QStringLiteral("symbolID"))
    {
        Q_ASSERT(value.isString());
        m_symbolID = value.toString();
        return true;
    }

    if(key == QStringLiteral("verticalRulerData"))
    {
        Q_ASSERT(value.isObject());
        m_verticalRulerData = ContainerFactory::createContainer<RulerData>(value.toObject(), this);
        return true;
    }

    return Artboard::parseProperty(key, value);
}
