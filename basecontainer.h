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
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)

protected:
    explicit BaseContainer(QObject *parent = nullptr);

public:
    const QString &do_objectID() const;

    void parseFromJson(const QJsonObject &jsonObj);

protected:
    virtual bool parseProperty(const QString &key, const QJsonValue &value);

private:
    static const QHash<QJsonValue::Type, QString> m_types;

    QString m_do_objectID;
};

#endif // BASECONTAINER_H
