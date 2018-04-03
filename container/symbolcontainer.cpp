#include "symbolcontainer.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>

SymbolContainer::SymbolContainer(QObject *parent) :
    BaseContainer(parent)
{
}

bool SymbolContainer::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("objects"))
    {
        Q_ASSERT(value.isArray());
        for(auto objectValue : value.toArray())
        {
            //TODO
            qWarning() << "objects not implemented";
        }
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
