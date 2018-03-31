#ifndef GROUP_H
#define GROUP_H

#include "basecontainer.h"

class QJsonObject;

class Group : public BaseContainer
{
    Q_OBJECT

public:
    explicit Group(QObject *parent = Q_NULLPTR);
    explicit Group(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // GROUP_H
