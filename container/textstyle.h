#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

#include "basecontainer.h"

class QJsonObject;

class TextStyle : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double verticalAlignment READ verticalAlignment CONSTANT)

public:
    Q_INVOKABLE explicit TextStyle(QObject *parent = Q_NULLPTR);

    double verticalAlignment() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    double m_verticalAlignment;
};

#endif // TEXTSTYLE_H
