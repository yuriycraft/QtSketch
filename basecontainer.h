#ifndef BASECONTAINER_H
#define BASECONTAINER_H

#include <QObject>

class QJsonObject;
class QJsonValue;

class BaseContainer : public QObject
{
    Q_OBJECT

protected:
    explicit BaseContainer(const QJsonObject &jsonObj, QObject *parent = nullptr);

    virtual bool parseProperty(const QString &key, const QJsonValue &value);
};

#endif // BASECONTAINER_H
