#ifndef GRADIENT_H
#define GRADIENT_H

#include "basecontainer.h"

class QJsonObject;

class GradientStop;

class Gradient : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double elipseLength READ elipseLength CONSTANT)
    Q_PROPERTY(QString from READ from CONSTANT)
    Q_PROPERTY(double gradientType READ gradientType CONSTANT)
    Q_PROPERTY(bool shouldSmoothenOpacity READ shouldSmoothenOpacity CONSTANT)
    Q_PROPERTY(QList<GradientStop*> stops READ stops CONSTANT)
    Q_PROPERTY(QString to READ to CONSTANT)

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
