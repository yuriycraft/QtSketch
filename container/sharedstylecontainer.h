#ifndef SHAREDSTYLECONTAINER_H
#define SHAREDSTYLECONTAINER_H

#include "basecontainer.h"

class QJsonObject;

class SharedStyle;

class SharedStyleContainer : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(QList<SharedStyle*> objects READ objects CONSTANT)

public:
    Q_INVOKABLE explicit SharedStyleContainer(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit SharedStyleContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    const QList<SharedStyle*> &objects() const;

private:
    QString m_do_objectID;
    QList<SharedStyle*> m_objects;
};

#endif // SHAREDSTYLECONTAINER_H
