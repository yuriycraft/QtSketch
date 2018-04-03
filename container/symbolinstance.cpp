#include "symbolinstance.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

SymbolInstance::SymbolInstance(QObject *parent) :
    Layer(parent),
    m_nameIsFixed(false),
    m_resizingConstraint(0.),
    m_resizingType(0.),
    m_scale(0.),
    m_shouldBreakMaskChain(false),
    m_verticalSpacing(0.),
    m_horizontalSpacing(0.),
    m_layerListExpandedType(0.),
    m_masterInfluenceEdgeMaxXPadding(0.),
    m_masterInfluenceEdgeMaxYPadding(0.),
    m_masterInfluenceEdgeMinXPadding(0.),
    m_masterInfluenceEdgeMinYPadding(0.)
{
}

bool SymbolInstance::nameIsFixed() const
{
    return m_nameIsFixed;
}

double SymbolInstance::resizingConstraint() const
{
    return m_resizingConstraint;
}

double SymbolInstance::resizingType() const
{
    return m_resizingType;
}

double SymbolInstance::scale() const
{
    return m_scale;
}

bool SymbolInstance::shouldBreakMaskChain() const
{
    return m_shouldBreakMaskChain;
}

const QString &SymbolInstance::symbolID() const
{
    return m_symbolID;
}

double SymbolInstance::verticalSpacing() const
{
    return m_verticalSpacing;
}

double SymbolInstance::horizontalSpacing() const
{
    return m_horizontalSpacing;
}

double SymbolInstance::layerListExpandedType() const
{
    return m_layerListExpandedType;
}

double SymbolInstance::masterInfluenceEdgeMaxXPadding() const
{
    return m_masterInfluenceEdgeMaxXPadding;
}

double SymbolInstance::masterInfluenceEdgeMaxYPadding() const
{
    return m_masterInfluenceEdgeMaxYPadding;
}

double SymbolInstance::masterInfluenceEdgeMinXPadding() const
{
    return m_masterInfluenceEdgeMinXPadding;
}

double SymbolInstance::masterInfluenceEdgeMinYPadding() const
{
    return m_masterInfluenceEdgeMinYPadding;
}

bool SymbolInstance::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("nameIsFixed"))
    {
        Q_ASSERT(value.isBool());
        m_nameIsFixed = value.toBool();
        return true;
    }

    if(key == QStringLiteral("overrideValues"))
    {
        Q_ASSERT(value.isArray());
        for(auto overrideValue : value.toArray())
        {
            Q_ASSERT(overrideValue.isObject());
            qWarning() << "overrideValues not implemented";
        }
        return true;
    }

    if(key == QStringLiteral("overrides"))
    {
        Q_ASSERT(value.isObject());
        qWarning() << "overrides not implemented";
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

    if(key == QStringLiteral("scale"))
    {
        Q_ASSERT(value.isDouble());
        m_scale = value.toDouble();
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

    if(key == QStringLiteral("verticalSpacing"))
    {
        Q_ASSERT(value.isDouble());
        m_verticalSpacing = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("horizontalSpacing"))
    {
        Q_ASSERT(value.isDouble());
        m_horizontalSpacing = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("layerListExpandedType"))
    {
        Q_ASSERT(value.isDouble());
        m_layerListExpandedType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("masterInfluenceEdgeMaxXPadding"))
    {
        Q_ASSERT(value.isDouble());
        m_masterInfluenceEdgeMaxXPadding = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("masterInfluenceEdgeMaxYPadding"))
    {
        Q_ASSERT(value.isDouble());
        m_masterInfluenceEdgeMaxYPadding = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("masterInfluenceEdgeMinXPadding"))
    {
        Q_ASSERT(value.isDouble());
        m_masterInfluenceEdgeMinXPadding = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("masterInfluenceEdgeMinYPadding"))
    {
        Q_ASSERT(value.isDouble());
        m_masterInfluenceEdgeMinYPadding = value.toDouble();
        return true;
    }

    return Layer::parseProperty(key, value);
}
