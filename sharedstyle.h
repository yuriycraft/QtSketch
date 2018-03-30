#ifndef SHAREDSTYLE_H
#define SHAREDSTYLE_H

#include "basecontainer.h"

class SharedStyle : public BaseContainer
{
    Q_OBJECT

public:
    explicit SharedStyle(QObject *parent = Q_NULLPTR);
    explicit SharedStyle(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);
};

#endif // SHAREDSTYLE_H
