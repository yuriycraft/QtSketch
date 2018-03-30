#ifndef SHAREDSTYLECONTAINER_H
#define SHAREDSTYLECONTAINER_H

#include "basecontainer.h"

class SharedStyle;

class SharedStyleContainer : public BaseContainer
{
    Q_OBJECT

public:
    explicit SharedStyleContainer(QObject *parent = Q_NULLPTR);
    explicit SharedStyleContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    QString m_do_objectID;
    QList<SharedStyle*> m_objects;
};

#endif // SHAREDSTYLECONTAINER_H
