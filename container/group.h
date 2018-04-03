#ifndef GROUP_H
#define GROUP_H

#include "basecontainer.h"

class QJsonObject;

class Group : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Group(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // GROUP_H
