#pragma once

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
    Q_INVOKABLE explicit Blur(QObject *parent = Q_NULLPTR);

    bool isEnabled() const;
    const QString &center() const;
    double motionAngle() const;
    double radius() const;
    double type() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    bool m_isEnabled;
    QString m_center;
    double m_motionAngle;
    double m_radius;
    double m_type;
};
