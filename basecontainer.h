#pragma once

#include <QObject>
#include <QHash>
#include <QMap>
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

    static const QMap<QString, int> &missing();

protected:
    virtual bool parseProperty(const QString &key, const QJsonValue &value);

private:
    static const QHash<QJsonValue::Type, QString> m_types;
    static QMap<QString, int> m_missing;

    QString m_do_objectID;
};
