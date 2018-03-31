#ifndef BLUR_H
#define BLUR_H

#include "basecontainer.h"

class QJsonObject;

class Blur : public BaseContainer
{
    Q_OBJECT

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
