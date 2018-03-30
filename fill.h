#ifndef FILL_H
#define FILL_H

#include "basecontainer.h"

class QJsonObject;

class Fill : public BaseContainer
{
    Q_OBJECT

public:
    explicit Fill(QObject *parent = Q_NULLPTR);
    explicit Fill(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);
};

#endif // FILL_H
