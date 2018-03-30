#ifndef UTILS_H
#define UTILS_H

#include <QObject>

class QString;
class QByteArray;
class QJsonDocument;
class QJsonObject;

class BaseContainer;

BaseContainer* createContainer(const QString &path, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(const QByteArray &content, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(const QJsonDocument &jsonDocument, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

template<typename T> T* createContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR)
{
    auto container = createContainer(jsonObj, parent);
    auto castedContainer = qobject_cast<T*>(container);

    if(castedContainer)
        return castedContainer;
    else
        throw QStringLiteral("not expected type");
}

#endif // UTILS_H
