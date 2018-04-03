#ifndef SLICE_H
#define SLICE_H

#include "layer.h"

class Slice : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Slice(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;
};

#endif // SLICE_H
