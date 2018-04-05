#ifndef POLYGON_H
#define POLYGON_H

#include "basecontainer.h"

class Polygon : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Polygon(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // POLYGON_H
