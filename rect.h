#ifndef RECT_H
#define RECT_H

#include "basecontainer.h"

class QJsonObject;

class Rect : public BaseContainer
{
    Q_OBJECT

public:
    explicit Rect(QObject *parent = Q_NULLPTR);
    explicit Rect(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // RECT_H
