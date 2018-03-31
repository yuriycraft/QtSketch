#ifndef SHAPEGROUP_H
#define SHAPEGROUP_H

#include "basecontainer.h"

class QJsonObject;

class ShapeGroup : public BaseContainer
{
    Q_OBJECT

public:
    explicit ShapeGroup(QObject *parent = Q_NULLPTR);
    explicit ShapeGroup(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // SHAPEGROUP_H
