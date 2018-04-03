#include "symbolcontainer.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

SymbolContainer::SymbolContainer(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
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
