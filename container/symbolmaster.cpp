#include "symbolmaster.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

#include "color.h"
#include "exportoptions.h"
#include "rect.h"
#include "rulerdata.h"
#include "style.h"

SymbolMaster::SymbolMaster(QObject *parent) :
    BaseContainer(parent),
    m_backgroundColor(Q_NULLPTR),
    m_changeIdentifier(0.),
    m_exportOptions(Q_NULLPTR),
    m_frame(Q_NULLPTR),
    m_hasBackgroundColor(false),
    m_hasClickThrough(false),
    m_horizontalRulerData(Q_NULLPTR),
    m_includeBackgroundColorInExport(false),
    m_includeBackgroundColorInInstance(false),
    m_includeInCloudUpload(false),
    m_isFlippedHorizontal(false),
    m_isFlippedVertical(false),
    m_isFlowHome(false),
    m_isLocked(false),
    m_isVisible(false),
    m_layerListExpandedType(0.),
    m_nameIsFixed(false),
    m_resizesContent(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_rotation(0.),
    m_shouldBreakMaskChain(false),
    m_style(Q_NULLPTR),
    m_verticalRulerData(Q_NULLPTR)
{
}

SymbolMaster::SymbolMaster(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_backgroundColor(Q_NULLPTR),
    m_changeIdentifier(0.),
    m_exportOptions(Q_NULLPTR),
    m_frame(Q_NULLPTR),
    m_hasBackgroundColor(false),
    m_hasClickThrough(false),
    m_horizontalRulerData(Q_NULLPTR),
    m_includeBackgroundColorInExport(false),
    m_includeBackgroundColorInInstance(false),
    m_includeInCloudUpload(false),
    m_isFlippedHorizontal(false),
    m_isFlippedVertical(false),
    m_isFlowHome(false),
    m_isLocked(false),
    m_isVisible(false),
    m_layerListExpandedType(0.),
    m_nameIsFixed(false),
    m_resizesContent(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_rotation(0.),
    m_shouldBreakMaskChain(false),
    m_style(Q_NULLPTR),
    m_verticalRulerData(Q_NULLPTR)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("backgroundColor"))
        {
            Q_ASSERT(iter.value().isObject());
            m_backgroundColor = createContainer<Color>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("changeIdentifier"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_changeIdentifier = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("do_objectID"))
        {
            Q_ASSERT(iter.value().isString());
            m_do_objectID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("exportOptions"))
        {
            Q_ASSERT(iter.value().isObject());
            m_exportOptions = createContainer<ExportOptions>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("frame"))
        {
            Q_ASSERT(iter.value().isObject());
            m_frame = createContainer<Rect>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("hasBackgroundColor"))
        {
            Q_ASSERT(iter.value().isBool());
            m_hasBackgroundColor = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("hasClickThrough"))
        {
            Q_ASSERT(iter.value().isBool());
            m_hasClickThrough = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("horizontalRulerData"))
        {
            Q_ASSERT(iter.value().isObject());
            m_horizontalRulerData = createContainer<RulerData>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("includeBackgroundColorInExport"))
        {
            Q_ASSERT(iter.value().isBool());
            m_includeBackgroundColorInExport = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("includeBackgroundColorInInstance"))
        {
            Q_ASSERT(iter.value().isBool());
            m_includeBackgroundColorInInstance = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("includeInCloudUpload"))
        {
            Q_ASSERT(iter.value().isBool());
            m_includeInCloudUpload = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("isFlippedHorizontal"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isFlippedHorizontal = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("isFlippedVertical"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isFlippedVertical = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("isFlowHome"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isFlowHome = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("isLocked"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isLocked = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("isVisible"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isVisible = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("layerListExpandedType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_layerListExpandedType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("layers"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto colorValue : iter.value().toArray())
            {
                Q_ASSERT(colorValue.isObject());
                //TODO
                qWarning() << "layers not implemented";
            }
        }
        else if(iter.key() == QStringLiteral("name"))
        {
            Q_ASSERT(iter.value().isString());
            m_name = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("nameIsFixed"))
        {
            Q_ASSERT(iter.value().isBool());
            m_nameIsFixed = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("resizesContent"))
        {
            Q_ASSERT(iter.value().isBool());
            m_resizesContent = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("resizingConstraint"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_resizingConstraint = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("resizingType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_resizingType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("rotation"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_rotation = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("shouldBreakMaskChain"))
        {
            Q_ASSERT(iter.value().isBool());
            m_shouldBreakMaskChain = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("style"))
        {
            Q_ASSERT(iter.value().isObject());
            m_style = createContainer<Style>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("symbolID"))
        {
            Q_ASSERT(iter.value().isString());
            m_symbolID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("verticalRulerData"))
        {
            Q_ASSERT(iter.value().isObject());
            m_verticalRulerData = createContainer<RulerData>(iter.value().toObject(), this);
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

const Color *SymbolMaster::backgroundColor() const
{
    return m_backgroundColor;
}

double SymbolMaster::changeIdentifier() const
{
    return m_changeIdentifier;
}

const QString &SymbolMaster::do_objectID() const
{
    return m_do_objectID;
}

const ExportOptions *SymbolMaster::exportOptions() const
{
    return m_exportOptions;
}

const Rect *SymbolMaster::frame() const
{
    return m_frame;
}

bool SymbolMaster::hasBackgroundColor() const
{
    return m_hasBackgroundColor;
}

bool SymbolMaster::hasClickThrough() const
{
    return m_hasClickThrough;
}

const RulerData *SymbolMaster::horizontalRulerData() const
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

bool SymbolMaster::isFlippedHorizontal() const
{
    return m_isFlippedHorizontal;
}

bool SymbolMaster::isFlippedVertical() const
{
    return m_isFlippedVertical;
}

bool SymbolMaster::isFlowHome() const
{
    return m_isFlowHome;
}

bool SymbolMaster::isLocked() const
{
    return m_isLocked;
}

bool SymbolMaster::isVisible() const
{
    return m_isVisible;
}

double SymbolMaster::layerListExpandedType() const
{
    return m_layerListExpandedType;
}

const QString &SymbolMaster::name() const
{
    return m_name;
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

double SymbolMaster::rotation() const
{
    return m_rotation;
}

bool SymbolMaster::shouldBreakMaskChain() const
{
    return m_shouldBreakMaskChain;
}

const Style *SymbolMaster::style() const
{
    return m_style;
}

const QString &SymbolMaster::symbolID() const
{
    return m_symbolID;
}

const RulerData *SymbolMaster::verticalRulerData() const
{
    return m_verticalRulerData;
}
