#ifndef BASECONTAINER_H
#define BASECONTAINER_H

#include <QObject>
#include <QHash>
#include <QJsonValue>

class QJsonObject;
class QJsonValue;

class BaseContainer : public QObject
{
    Q_OBJECT

protected:
    explicit BaseContainer(QObject *parent = nullptr);

public:
    void parseFromJson(const QJsonObject &jsonObj);

protected:
    virtual bool parseProperty(const QString &key, const QJsonValue &value);

private:
    static const QHash<QJsonValue::Type, QString> m_types;
};

#endif // BASECONTAINER_H
