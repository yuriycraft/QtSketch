#ifndef RULERDATA_H
#define RULERDATA_H

#include "basecontainer.h"

class QJsonObject;

class RulerData : public BaseContainer
{
    Q_OBJECT

public:
    explicit RulerData(QObject *parent = Q_NULLPTR);
    explicit RulerData(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    double m_base;
};

#endif // RULERDATA_H
