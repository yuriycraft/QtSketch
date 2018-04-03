#include "msimmutableforeignsymbol.h"

#include <QDebug>
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

MSImmutableForeignSymbol::MSImmutableForeignSymbol(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_originalMaster(Q_NULLPTR),
    m_symbolMaster(Q_NULLPTR)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("do_objectID"))
        {
            Q_ASSERT(iter.value().isString());
            m_do_objectID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("libraryID"))
        {
            Q_ASSERT(iter.value().isString());
            m_libraryID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("originalMaster"))
        {
            Q_ASSERT(iter.value().isObject());
            m_originalMaster = ContainerFactory::createContainer<SymbolMaster>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("sourceLibraryName"))
        {
            Q_ASSERT(iter.value().isString());
            m_sourceLibraryName = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("symbolMaster"))
        {
            Q_ASSERT(iter.value().isObject());
            m_symbolMaster = ContainerFactory::createContainer<SymbolMaster>(iter.value().toObject(), this);
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
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
