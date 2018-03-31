#ifndef RULERDATA_H
#define RULERDATA_H

#include "basecontainer.h"

class QJsonObject;

class RulerData : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double base READ base CONSTANT)

public:
    explicit RulerData(QObject *parent = Q_NULLPTR);
    explicit RulerData(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    double base() const;

private:
    double m_base;
};

#endif // RULERDATA_H
