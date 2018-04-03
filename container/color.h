#ifndef COLOR_H
#define COLOR_H

#include "basecontainer.h"

class QJsonObject;

class Color : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double alpha READ alpha CONSTANT)
    Q_PROPERTY(double blue READ blue CONSTANT)
    Q_PROPERTY(double green READ green CONSTANT)
    Q_PROPERTY(double red READ red CONSTANT)

public:
    Q_INVOKABLE explicit Color(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit Color(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    double alpha() const;
    double blue() const;
    double green() const;
    double red() const;

private:
    double m_alpha;
    double m_blue;
    double m_green;
    double m_red;
};

#endif // COLOR_H
