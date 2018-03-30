#include "symbolcontainer.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

SymbolContainer::SymbolContainer(QObject *parent) :
    BaseContainer(parent)
{
}

SymbolContainer::SymbolContainer(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("objects"))
        {
            Q_ASSERT(iter.value().isArray());
            //TODO
            qWarning() << "objects not implemented";
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}
