#include "page.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

#include "exportoptions.h"
#include "rect.h"
#include "style.h"
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

Page::Page(const QJsonObject &jsonObj, QObject *parent) :
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
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
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
        else if(iter.key() == QStringLiteral("layers"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto layerValue : iter.value().toArray())
            {
                //TODO
                qDebug() << "layers not implemented";
            }
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
        else if(iter.key() == QStringLiteral("includeInCloudUpload"))
        {
            Q_ASSERT(iter.value().isBool());
            m_includeInCloudUpload = iter.value().toBool();
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
