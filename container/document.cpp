#include "document.h"

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "assetcollection.h"
#include "msimmutableforeignsymbol.h"
#include "sharedstylecontainer.h"
#include "symbolcontainer.h"
#include "sharedtextstylecontainer.h"
#include "msjsonfilereference.h"

Document::Document(QObject *parent) :
    BaseContainer(parent),
    m_assets(Q_NULLPTR),
    m_colorSpace(0.),
    m_currentPageIndex(0.),
    m_enableLayerInteraction(false),
    m_enableSliceInteraction(false),
    m_layerStyles(Q_NULLPTR),
    m_layerSymbols(Q_NULLPTR),
    m_layerTextStyles(Q_NULLPTR)
{
}

AssetCollection *Document::assets() const
{
    return m_assets;
}

double Document::colorSpace() const
{
    return m_colorSpace;
}

double Document::currentPageIndex() const
{
    return m_currentPageIndex;
}

bool Document::enableLayerInteraction() const
{
    return m_enableLayerInteraction;
}

bool Document::enableSliceInteraction() const
{
    return m_enableSliceInteraction;
}

const QList<MSImmutableForeignSymbol *> &Document::foreignSymbols() const
{
    return m_foreignSymbols;
}

SharedStyleContainer *Document::layerStyles() const
{
    return m_layerStyles;
}

SymbolContainer *Document::layerSymbols() const
{
    return m_layerSymbols;
}

SharedTextStyleContainer *Document::layerTextStyles() const
{
    return m_layerTextStyles;
}

const QList<MSJSONFileReference *> &Document::pages() const
{
    return m_pages;
}

bool Document::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("assets"))
    {
        Q_ASSERT(value.isObject());
        m_assets = ContainerFactory::createContainer<AssetCollection>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("colorSpace"))
    {
        Q_ASSERT(value.isDouble());
        m_colorSpace = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("currentPageIndex"))
    {
        Q_ASSERT(value.isDouble());
        m_currentPageIndex = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("enableLayerInteraction"))
    {
        Q_ASSERT(value.isBool());
        m_enableLayerInteraction = value.toBool();
        return true;
    }

    if(key == QStringLiteral("enableSliceInteraction"))
    {
        Q_ASSERT(value.isBool());
        m_enableSliceInteraction = value.toBool();
        return true;
    }

    if(key == QStringLiteral("foreignSymbols"))
    {
        Q_ASSERT(value.isArray());
        for(auto pageValue : value.toArray())
        {
            Q_ASSERT(pageValue.isObject());
            m_foreignSymbols.append(ContainerFactory::createContainer<MSImmutableForeignSymbol>(pageValue.toObject(), this));
        }
        return true;
    }

    if(key == QStringLiteral("layerStyles"))
    {
        Q_ASSERT(value.isObject());
        m_layerStyles = ContainerFactory::createContainer<SharedStyleContainer>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("layerSymbols"))
    {
        Q_ASSERT(value.isObject());
        m_layerSymbols = ContainerFactory::createContainer<SymbolContainer>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("layerTextStyles"))
    {
        Q_ASSERT(value.isObject());
        m_layerTextStyles = ContainerFactory::createContainer<SharedTextStyleContainer>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("pages"))
    {
        Q_ASSERT(value.isArray());
        for(auto pageValue : value.toArray())
        {
            Q_ASSERT(pageValue.isObject());
            m_pages.append(ContainerFactory::createContainer<MSJSONFileReference>(pageValue.toObject(), this));
        }
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
