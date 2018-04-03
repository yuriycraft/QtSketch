#ifndef TEXT_H
#define TEXT_H

#include "basecontainer.h"

class QJsonObject;

class Text : public BaseContainer
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Text(QObject *parent = Q_NULLPTR);

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
};

#endif // TEXT_H
