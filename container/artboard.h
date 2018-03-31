#ifndef ARTBOARD_H
#define ARTBOARD_H

#include "basecontainer.h"

class QJsonObject;

class Artboard : public BaseContainer
{
    Q_OBJECT

public:
    explicit Artboard(QObject *parent = Q_NULLPTR);
    explicit Artboard(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // ARTBOARD_H
