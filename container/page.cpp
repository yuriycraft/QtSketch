#include "page.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "exportoptions.h"
#include "rect.h"
#include "style.h"
#include "symbolmaster.h"
#include "rulerdata.h"

Page::Page(QObject *parent) :
    BaseContainer(parent),
    m_exportOptions(Q_NULLPTR),
    m_frame(Q_NULLPTR),
    m_isFlippedHorizontal(false),
    m_isFlippedVertical(false),
    m_isLocked(false),
    m_isVisible(false),
    m_layerListExpandedType(0.),
    m_nameIsFixed(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_rotation(0.),
    m_shouldBreakMaskChain(false),
    m_style(Q_NULLPTR),
    m_hasClickThrough(false),
    m_horizontalRulerData(Q_NULLPTR),
    m_includeInCloudUpload(false),
    m_verticalRulerData(Q_NULLPTR)
{
}

const QString &Page::do_objectID() const
{
    return m_do_objectID;
}

ExportOptions *Page::exportOptions() const
{
    return m_exportOptions;
}

Rect *Page::frame() const
{
    return m_frame;
}

bool Page::isFlippedHorizontal() const
{
    return m_isFlippedHorizontal;
}

bool Page::isFlippedVertical() const
{
    return m_isFlippedVertical;
}

bool Page::isLocked() const
{
    return m_isLocked;
}

bool Page::isVisible() const
{
    return m_isVisible;
}

double Page::layerListExpandedType() const
{
    return m_layerListExpandedType;
}

const QString &Page::name() const
{
    return m_name;
}

bool Page::nameIsFixed() const
{
    return m_nameIsFixed;
}

double Page::resizingConstraint() const
{
    return m_resizingConstraint;
}

double Page::resizingType() const
{
    return m_resizingType;
}

double Page::rotation() const
{
    return m_rotation;
}

bool Page::shouldBreakMaskChain() const
{
    return m_shouldBreakMaskChain;
}

Style *Page::style() const
{
    return m_style;
}

bool Page::hasClickThrough() const
{
    return m_hasClickThrough;
}

const QList<SymbolMaster *> &Page::layers() const
{
    return m_layers;
}

RulerData *Page::horizontalRulerData() const
{
    return m_horizontalRulerData;
}

bool Page::includeInCloudUpload() const
{
    return m_includeInCloudUpload;
}

RulerData *Page::verticalRulerData() const
{
    return m_verticalRulerData;
}

bool Page::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("exportOptions"))
    {
        Q_ASSERT(value.isObject());
        m_exportOptions = ContainerFactory::createContainer<ExportOptions>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("frame"))
    {
        Q_ASSERT(value.isObject());
        m_frame = ContainerFactory::createContainer<Rect>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("isFlippedHorizontal"))
    {
        Q_ASSERT(value.isBool());
        m_isFlippedHorizontal = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isFlippedVertical"))
    {
        Q_ASSERT(value.isBool());
        m_isFlippedVertical = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isLocked"))
    {
        Q_ASSERT(value.isBool());
        m_isLocked = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isVisible"))
    {
        Q_ASSERT(value.isBool());
        m_isVisible = value.toBool();
        return true;
    }

    if(key == QStringLiteral("layerListExpandedType"))
    {
        Q_ASSERT(value.isDouble());
        m_layerListExpandedType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("name"))
    {
        Q_ASSERT(value.isString());
        m_name = value.toString();
        return true;
    }

    if(key == QStringLiteral("nameIsFixed"))
    {
        Q_ASSERT(value.isBool());
        m_nameIsFixed = value.toBool();
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

    if(key == QStringLiteral("rotation"))
    {
        Q_ASSERT(value.isDouble());
        m_rotation = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("shouldBreakMaskChain"))
    {
        Q_ASSERT(value.isBool());
        m_shouldBreakMaskChain = value.toBool();
        return true;
    }

    if(key == QStringLiteral("style"))
    {
        Q_ASSERT(value.isObject());
        m_style = ContainerFactory::createContainer<Style>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("layers"))
    {
        Q_ASSERT(value.isArray());
        for(auto layerValue : value.toArray())
        {
            Q_ASSERT(layerValue.isObject());
            m_layers.append(ContainerFactory::createContainer<SymbolMaster>(layerValue.toObject(), this));
        }
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

    if(key == QStringLiteral("includeInCloudUpload"))
    {
        Q_ASSERT(value.isBool());
        m_includeInCloudUpload = value.toBool();
        return true;
    }

    if(key == QStringLiteral("verticalRulerData"))
    {
        Q_ASSERT(value.isObject());
        m_verticalRulerData = ContainerFactory::createContainer<RulerData>(value.toObject(), this);
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
