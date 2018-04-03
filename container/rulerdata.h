#ifndef RULERDATA_H
#define RULERDATA_H

#include "basecontainer.h"

class QJsonObject;

class RulerData : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double base READ base CONSTANT)

public:
    Q_INVOKABLE explicit RulerData(QObject *parent = Q_NULLPTR);

    double base() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    double m_base;
};

#endif // RULERDATA_H
