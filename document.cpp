#include "document.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

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

Document::Document(const QJsonObject &jsonObj, QObject *parent) :
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
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("assets"))
        {
            Q_ASSERT(iter.value().isObject());
            m_assets = createContainer<AssetCollection>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("colorSpace"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_colorSpace = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("currentPageIndex"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_currentPageIndex = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("do_objectID"))
        {
            Q_ASSERT(iter.value().isString());
            m_do_objectID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("enableLayerInteraction"))
        {
            Q_ASSERT(iter.value().isBool());
            m_enableLayerInteraction = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("enableSliceInteraction"))
        {
            Q_ASSERT(iter.value().isBool());
            m_enableSliceInteraction = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("foreignSymbols"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto pageValue : iter.value().toArray())
            {
                Q_ASSERT(pageValue.isObject());
                m_foreignSymbols.append(createContainer<MSImmutableForeignSymbol>(pageValue.toObject(), this));
            }
        }
        else if(iter.key() == QStringLiteral("layerStyles"))
        {
            Q_ASSERT(iter.value().isObject());
            m_layerStyles = createContainer<SharedStyleContainer>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("layerSymbols"))
        {
            Q_ASSERT(iter.value().isObject());
            m_layerSymbols = createContainer<SymbolContainer>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("layerTextStyles"))
        {
            Q_ASSERT(iter.value().isObject());
            m_layerTextStyles = createContainer<SharedTextStyleContainer>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("pages"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto pageValue : iter.value().toArray())
            {
                Q_ASSERT(pageValue.isObject());
                m_pages.append(createContainer<MSJSONFileReference>(pageValue.toObject(), this));
            }
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

const AssetCollection *Document::assets() const
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

const QString Document::do_objectID() const
{
    return m_do_objectID;
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

const SharedStyleContainer *Document::layerStyles() const
{
    return m_layerStyles;
}

const SymbolContainer *Document::layerSymbols() const
{
    return m_layerSymbols;
}

const SharedTextStyleContainer *Document::layerTextStyles() const
{
    return m_layerTextStyles;
}

const QList<MSJSONFileReference *> &Document::pages() const
{
    return m_pages;
}
