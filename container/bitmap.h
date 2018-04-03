#ifndef BITMAP_H
#define BITMAP_H

#include "layer.h"

class Bitmap : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Bitmap(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;
};

#endif // BITMAP_H
