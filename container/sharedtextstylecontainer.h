#ifndef SHAREDTEXTSTYLECONTAINER_H
#define SHAREDTEXTSTYLECONTAINER_H

#include "basecontainer.h"

class QJsonObject;

class SharedStyle;

class SharedTextStyleContainer : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QList<SharedStyle*> objects READ objects CONSTANT)

public:
    explicit SharedTextStyleContainer(QObject *parent = Q_NULLPTR);
    explicit SharedTextStyleContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QList<SharedStyle*> &objects() const;

private:
    QList<SharedStyle*> m_objects;
};

#endif // SHAREDTEXTSTYLECONTAINER_H
