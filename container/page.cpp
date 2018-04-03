#include "page.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "exportoptions.h"
#include "rect.h"
#include "style.h"
#include "symbolmaster.h"
#include "rulerdata.h"

Page::Page(QObject *parent) :
    Group(parent),
    m_exportOptions(Q_NULLPTR),
    m_isLocked(false),
    m_layerListExpandedType(0.),
    m_nameIsFixed(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_shouldBreakMaskChain(false),
    m_hasClickThrough(false),
    m_horizontalRulerData(Q_NULLPTR),
    m_includeInCloudUpload(false),
    m_verticalRulerData(Q_NULLPTR)
{
}

ExportOptions *Page::exportOptions() const
{
    return m_exportOptions;
}

bool Page::isLocked() const
{
    return m_isLocked;
}

double Page::layerListExpandedType() const
{
    return m_layerListExpandedType;
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

bool Page::shouldBreakMaskChain() const
{
    return m_shouldBreakMaskChain;
}

bool Page::hasClickThrough() const
{
    return m_hasClickThrough;
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
    if(key == QStringLiteral("exportOptions"))
    {
        Q_ASSERT(value.isObject());
        m_exportOptions = ContainerFactory::createContainer<ExportOptions>(value.toObject(), this);
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

    return Group::parseProperty(key, value);
}
