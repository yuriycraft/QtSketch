#ifndef OVAL_H
#define OVAL_H

#include "layer.h"

class Oval : public Layer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Oval(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;
};

#endif // OVAL_H
