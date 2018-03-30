#ifndef COLOR_H
#define COLOR_H

#include "basecontainer.h"

class QJsonObject;

class Color : public BaseContainer
{
    Q_OBJECT

public:
    explicit Color(QObject *parent = Q_NULLPTR);
    explicit Color(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    double m_alpha;
    double m_blue;
    double m_green;
    double m_red;
};

#endif // COLOR_H
