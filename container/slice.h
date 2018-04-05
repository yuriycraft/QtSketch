#ifndef SLICE_H
#define SLICE_H

#include "layer.h"

class Color;

class Slice : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Slice(QObject *parent = Q_NULLPTR);

    Color *backgroundColor() const;
    bool hasBackgroundColor() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    Color *m_backgroundColor;
    bool m_hasBackgroundColor;
};

#endif // SLICE_H
