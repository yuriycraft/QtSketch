#ifndef SHAREDTEXTSTYLECONTAINER_H
#define SHAREDTEXTSTYLECONTAINER_H

#include "basecontainer.h"

class SharedStyle;

class SharedTextStyleContainer : public BaseContainer
{
    Q_OBJECT

public:
    explicit SharedTextStyleContainer(QObject *parent = Q_NULLPTR);
    explicit SharedTextStyleContainer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    QList<SharedStyle*> m_objects;
};

#endif // SHAREDTEXTSTYLECONTAINER_H
