#ifndef STYLE_H
#define STYLE_H

#include "basecontainer.h"

class QJsonObject;

class Style : public BaseContainer
{
    Q_OBJECT

public:
    explicit Style(QObject *parent = Q_NULLPTR);
    explicit Style(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);
};

#endif // STYLE_H
