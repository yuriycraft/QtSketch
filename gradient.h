#ifndef GRADIENT_H
#define GRADIENT_H

#include "basecontainer.h"

class QJsonObject;

class GradientStop;

class Gradient : public BaseContainer
{
    Q_OBJECT

public:
    explicit Gradient(QObject *parent = Q_NULLPTR);
    explicit Gradient(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    double m_elipseLength;
    QString m_from;
    double m_gradientType;
    bool m_shouldSmoothenOpacity;
    QList<GradientStop*> m_stops;
    QString m_to;
};

#endif // GRADIENT_H
