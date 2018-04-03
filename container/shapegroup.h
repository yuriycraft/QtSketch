#ifndef SHAPEGROUP_H
#define SHAPEGROUP_H

#include "basecontainer.h"

class QJsonObject;

class ShapeGroup : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit ShapeGroup(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // SHAPEGROUP_H
