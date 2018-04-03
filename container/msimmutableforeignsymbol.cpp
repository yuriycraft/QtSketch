#include "msimmutableforeignsymbol.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "symbolmaster.h"

MSImmutableForeignSymbol::MSImmutableForeignSymbol(QObject *parent) :
    BaseContainer(parent),
    m_originalMaster(Q_NULLPTR),
    m_symbolMaster(Q_NULLPTR)
{
}

const QString &MSImmutableForeignSymbol::do_objectID() const
{
    return m_do_objectID;
}

const QString &MSImmutableForeignSymbol::libraryID() const
{
    return m_libraryID;
}

SymbolMaster *MSImmutableForeignSymbol::originalMaster() const
{
    return m_originalMaster;
}

const QString &MSImmutableForeignSymbol::sourceLibraryName() const
{
    return m_sourceLibraryName;
}

SymbolMaster *MSImmutableForeignSymbol::symbolMaster() const
{
    return m_symbolMaster;
}

bool MSImmutableForeignSymbol::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("libraryID"))
    {
        Q_ASSERT(value.isString());
        m_libraryID = value.toString();
        return true;
    }

    if(key == QStringLiteral("originalMaster"))
    {
        Q_ASSERT(value.isObject());
        m_originalMaster = ContainerFactory::createContainer<SymbolMaster>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("sourceLibraryName"))
    {
        Q_ASSERT(value.isString());
        m_sourceLibraryName = value.toString();
        return true;
    }

    if(key == QStringLiteral("symbolMaster"))
    {
        Q_ASSERT(value.isObject());
        m_symbolMaster = ContainerFactory::createContainer<SymbolMaster>(value.toObject(), this);
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
