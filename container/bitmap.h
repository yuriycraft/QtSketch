#ifndef BITMAP_H
#define BITMAP_H

#include "layer.h"

class MSJSONFileReference;

class Bitmap : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Bitmap(QObject *parent = Q_NULLPTR);

    MSJSONFileReference *image() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    MSJSONFileReference *m_image;
};

#endif // BITMAP_H
