#ifndef SHAPEPATH_H
#define SHAPEPATH_H

#include "layer.h"

class ShapePath : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit ShapePath(QObject *parent = nullptr);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;
};

#endif // SHAPEPATH_H
