#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

#include "basecontainer.h"

class QJsonObject;

class TextStyle : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit TextStyle(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // TEXTSTYLE_H
