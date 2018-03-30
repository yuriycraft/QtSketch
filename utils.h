#ifndef UTILS_H
#define UTILS_H

#include <QObject>

class QString;
class QByteArray;
class QJsonDocument;
class QJsonObject;

class BaseContainer;

BaseContainer* getContainer(const QString &path);

BaseContainer* getContainer(const QByteArray &content);

BaseContainer* getContainer(const QJsonDocument &jsonDocument);

BaseContainer* getContainer(const QJsonObject &jsonObj);

template<typename T> T* getContainer(const QJsonObject &jsonObj)
{
    auto container = getContainer(jsonObj);
    auto castedContainer = qobject_cast<T*>(container);

    if(castedContainer)
        return castedContainer;
    else
        throw QStringLiteral("not expected type");
}

#endif // UTILS_H
