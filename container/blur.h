#ifndef BLUR_H
#define BLUR_H

#include "basecontainer.h"

class QJsonObject;

class Blur : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(bool isEnabled READ isEnabled CONSTANT)
    Q_PROPERTY(QString center READ center CONSTANT)
    Q_PROPERTY(double motionAngle READ motionAngle CONSTANT)
    Q_PROPERTY(double radius READ radius CONSTANT)
    Q_PROPERTY(double type READ type CONSTANT)

public:
    explicit Blur(QObject *parent = Q_NULLPTR);
    explicit Blur(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    bool isEnabled() const;
    const QString &center() const;
    double motionAngle() const;
    double radius() const;
    double type() const;

private:
    bool m_isEnabled;
    QString m_center;
    double m_motionAngle;
    double m_radius;
    double m_type;
};

#endif // BLUR_H
