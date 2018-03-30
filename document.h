#ifndef DOCUMENT_H
#define DOCUMENT_H

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

public:
    explicit Document(QObject *parent = Q_NULLPTR);
    explicit Document(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    AssetCollection *m_assets;
    double m_colorSpace;
    double m_currentPageIndex;
    QString m_do_objectID;
    bool m_enableLayerInteraction;
    bool m_enableSliceInteraction;
    QList<MSImmutableForeignSymbol*> m_foreignSymbols;
    SharedStyleContainer *m_layerStyles;
    SymbolContainer *m_layerSymbols;
    SharedTextStyleContainer *m_layerTextStyles;
    QList<MSJSONFileReference*> m_pages;
};

#endif // DOCUMENT_H
