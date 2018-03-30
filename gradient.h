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

    double elipseLength() const;
    const QString &from() const;
    double gradientType() const;
    bool shouldSmoothenOpacity() const;
    const QList<GradientStop*> &stops() const;
    const QString &to() const;

private:
    double m_elipseLength;
    QString m_from;
    double m_gradientType;
    bool m_shouldSmoothenOpacity;
    QList<GradientStop*> m_stops;
    QString m_to;
};

#endif // GRADIENT_H
