#pragma once

#include "basecontainer.h"

class QJsonObject;

class SymbolMaster;

class MSImmutableForeignSymbol : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString libraryID READ libraryID CONSTANT)
    Q_PROPERTY(SymbolMaster* originalMaster READ originalMaster CONSTANT)
    Q_PROPERTY(QString sourceLibraryName READ sourceLibraryName CONSTANT)
    Q_PROPERTY(SymbolMaster* symbolMaster READ symbolMaster CONSTANT)

public:
    Q_INVOKABLE explicit MSImmutableForeignSymbol(QObject *parent = Q_NULLPTR);

    const QString &libraryID() const;
    SymbolMaster *originalMaster() const;
    const QString &sourceLibraryName() const;
    SymbolMaster *symbolMaster() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QString m_libraryID;
    SymbolMaster *m_originalMaster;
    QString m_sourceLibraryName;
    SymbolMaster *m_symbolMaster;
};
