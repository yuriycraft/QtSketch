#include "layer.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "container/rect.h"
#include "container/style.h"
#include "container/exportoptions.h"

Layer::Layer(QObject *parent) :
    BaseContainer(parent),
    m_frame(Q_NULLPTR),
    m_isFlippedVertical(false),
    m_isFlippedHorizontal(false),
    m_isVisible(false),
    m_resizingConstraints(ResizingConstraint::None),
    m_rotation(0.),
    m_style(Q_NULLPTR),
    m_exportOptions(Q_NULLPTR),
    m_isLocked(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_shouldBreakMaskChain(false)
{
}

const QString &Layer::do_objectID() const
{
    return m_do_objectID;
}

const QString &Layer::name() const
{
    return m_name;
}

bool Layer::nameIsFixed() const
{
    return m_nameIsFixed;
}

Rect *Layer::frame() const
{
    return m_frame;
}

bool Layer::isFlippedVertical() const
{
    return m_isFlippedVertical;
}

bool Layer::isFlippedHorizontal() const
{
    return m_isFlippedHorizontal;
}

bool Layer::isVisible() const
{
    return m_isVisible;
}

Layer::ResizingConstraint Layer::resizingConstraints() const
{
    return m_resizingConstraints;
}

double Layer::rotation() const
{
    return m_rotation;
}

Style *Layer::style() const
{
    return m_style;
}

ExportOptions *Layer::exportOptions() const
{
    return m_exportOptions;
}

bool Layer::isLocked() const
{
    return m_isLocked;
}

double Layer::resizingConstraint() const
{
    return m_resizingConstraint;
}

double Layer::resizingType() const
{
    return m_resizingType;
}

bool Layer::shouldBreakMaskChain() const
{
    return m_shouldBreakMaskChain;
}

bool Layer::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
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

    if(key == QStringLiteral("frame"))
    {
        Q_ASSERT(value.isObject());
        m_frame = ContainerFactory::createContainer<Rect>(value.toObject());
        return true;
    }

    if(key == QStringLiteral("isFlippedVertical"))
    {
        Q_ASSERT(value.isBool());
        m_isFlippedVertical = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isFlippedHorizontal"))
    {
        Q_ASSERT(value.isBool());
        m_isFlippedHorizontal = value.toBool();
        return true;
    }

    if(key == QStringLiteral("isVisible"))
    {
        Q_ASSERT(value.isBool());
        m_isVisible = value.toBool();
        return true;
    }

    if(key == QStringLiteral("resizingConstraints"))
    {
        Q_ASSERT(value.isDouble());
        m_resizingConstraints = ResizingConstraint(int(value.toDouble()));
        return true;
    }

    if(key == QStringLiteral("rotation"))
    {
        Q_ASSERT(value.isDouble());
        m_rotation = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("style"))
    {
        Q_ASSERT(value.isObject());
        m_style = ContainerFactory::createContainer<Style>(value.toObject());
        return true;
    }

    if(key == QStringLiteral("exportOptions"))
    {
        Q_ASSERT(value.isObject());
        m_exportOptions = ContainerFactory::createContainer<ExportOptions>(value.toObject());
        return true;
    }

    if(key == QStringLiteral("isLocked"))
    {
        Q_ASSERT(value.isBool());
        m_isLocked = value.toBool();
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

    return BaseContainer::parseProperty(key, value);
}
