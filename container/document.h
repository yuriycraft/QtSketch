#pragma once

#include "basecontainer.h"

class QJsonObject;

class AssetCollection;
class MSImmutableForeignSymbol;
class SharedStyleContainer;
class SymbolContainer;
class SharedTextStyleContainer;
class MSJSONFileReference;

class Document : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(AssetCollection* assets READ assets CONSTANT)
    Q_PROPERTY(double colorSpace READ colorSpace CONSTANT)
    Q_PROPERTY(double currentPageIndex READ currentPageIndex CONSTANT)
    Q_PROPERTY(bool enableLayerInteraction READ enableLayerInteraction CONSTANT)
    Q_PROPERTY(bool enableSliceInteraction READ enableSliceInteraction CONSTANT)
    Q_PROPERTY(QList<MSImmutableForeignSymbol*> foreignSymbols READ foreignSymbols CONSTANT)
    Q_PROPERTY(SharedStyleContainer* layerStyles READ layerStyles CONSTANT)
    Q_PROPERTY(SymbolContainer* layerSymbols READ layerSymbols CONSTANT)
    Q_PROPERTY(SharedTextStyleContainer* layerTextStyles READ layerTextStyles CONSTANT)
    Q_PROPERTY(QList<MSJSONFileReference*> pages READ pages CONSTANT)

public:
    Q_INVOKABLE explicit Document(QObject *parent = Q_NULLPTR);

    AssetCollection *assets() const;
    double colorSpace() const;
    double currentPageIndex() const;
    bool enableLayerInteraction() const;
    bool enableSliceInteraction() const;
    const QList<MSImmutableForeignSymbol*> &foreignSymbols() const;
    SharedStyleContainer *layerStyles() const;
    SymbolContainer *layerSymbols() const;
    SharedTextStyleContainer *layerTextStyles() const;
    const QList<MSJSONFileReference*> &pages() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    AssetCollection *m_assets;
    double m_colorSpace;
    double m_currentPageIndex;
    bool m_enableLayerInteraction;
    bool m_enableSliceInteraction;
    QList<MSImmutableForeignSymbol*> m_foreignSymbols;
    SharedStyleContainer *m_layerStyles;
    SymbolContainer *m_layerSymbols;
    SharedTextStyleContainer *m_layerTextStyles;
    QList<MSJSONFileReference*> m_pages;
};
