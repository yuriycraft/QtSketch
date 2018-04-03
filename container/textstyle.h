#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

#include "basecontainer.h"

class QJsonObject;

class TextStyle : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit TextStyle(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit TextStyle(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // TEXTSTYLE_H
