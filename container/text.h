#ifndef TEXT_H
#define TEXT_H

#include "basecontainer.h"

class QJsonObject;

class Text : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Text(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit Text(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // TEXT_H
