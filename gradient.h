#ifndef GRADIENT_H
#define GRADIENT_H

#include "basecontainer.h"

class QJsonObject;

class Gradient : public BaseContainer
{
    Q_OBJECT

public:
    explicit Gradient(QObject *parent = Q_NULLPTR);
    explicit Gradient(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // GRADIENT_H
