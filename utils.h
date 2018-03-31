#ifndef UTILS_H
#define UTILS_H

#include <QObject>

class QString;
class QIODevice;
class QByteArray;
class QJsonDocument;
class QJsonObject;

class BaseContainer;

BaseContainer* createContainer(const QString &path, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(QIODevice &device, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(const QByteArray &content, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(const QJsonDocument &jsonDocument, QObject *parent = Q_NULLPTR);

BaseContainer* createContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

template<typename T1, typename T2> T1* createContainer(const T2 &arg, QObject *parent = Q_NULLPTR)
{
    auto container = createContainer(arg, parent);
    auto castedContainer = qobject_cast<T1*>(container);

    if(castedContainer)
        return castedContainer;
    else
        throw QStringLiteral("not expected type");
}

#endif // UTILS_H
