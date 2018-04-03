#ifndef MSIMMUTABLEFOREIGNSYMBOL_H
#define MSIMMUTABLEFOREIGNSYMBOL_H

#include "basecontainer.h"

class QJsonObject;

class SymbolMaster;

class MSImmutableForeignSymbol : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(QString libraryID READ libraryID CONSTANT)
    Q_PROPERTY(SymbolMaster* originalMaster READ originalMaster CONSTANT)
    Q_PROPERTY(QString sourceLibraryName READ sourceLibraryName CONSTANT)
    Q_PROPERTY(SymbolMaster* symbolMaster READ symbolMaster CONSTANT)

public:
    Q_INVOKABLE explicit MSImmutableForeignSymbol(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit MSImmutableForeignSymbol(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    const QString &libraryID() const;
    SymbolMaster *originalMaster() const;
    const QString &sourceLibraryName() const;
    SymbolMaster *symbolMaster() const;

private:
    QString m_do_objectID;
    QString m_libraryID;
    SymbolMaster *m_originalMaster;
    QString m_sourceLibraryName;
    SymbolMaster *m_symbolMaster;
};

#endif // MSIMMUTABLEFOREIGNSYMBOL_H
