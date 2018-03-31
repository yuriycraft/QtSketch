#ifndef MSIMMUTABLEFOREIGNSYMBOL_H
#define MSIMMUTABLEFOREIGNSYMBOL_H

#include "basecontainer.h"

class QJsonObject;

class SymbolMaster;

class MSImmutableForeignSymbol : public BaseContainer
{
    Q_OBJECT

public:
    explicit MSImmutableForeignSymbol(QObject *parent = Q_NULLPTR);
    explicit MSImmutableForeignSymbol(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    const QString &libraryID() const;
    const SymbolMaster *originalMaster() const;
    const QString &sourceLibraryName() const;
    const SymbolMaster *symbolMaster() const;

private:
    QString m_do_objectID;
    QString m_libraryID;
    SymbolMaster *m_originalMaster;
    QString m_sourceLibraryName;
    SymbolMaster *m_symbolMaster;
};

#endif // MSIMMUTABLEFOREIGNSYMBOL_H
