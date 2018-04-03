#ifndef ARTBOARD_H
#define ARTBOARD_H

#include "basecontainer.h"

class Artboard : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Artboard(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // ARTBOARD_H
