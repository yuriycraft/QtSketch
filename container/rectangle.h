#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "layer.h"

class Rectangle : public Layer
{
    Q_OBJECT

public:
    explicit Rectangle(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;
};

#endif // RECTANGLE_H
