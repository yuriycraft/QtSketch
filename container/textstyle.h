#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

#include "basecontainer.h"

class QJsonObject;

class TextStyle : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(double verticalAlignment READ verticalAlignment CONSTANT)

public:
    Q_INVOKABLE explicit TextStyle(QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    double verticalAlignment() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QString m_do_objectID;
    double m_verticalAlignment;
};

#endif // TEXTSTYLE_H
