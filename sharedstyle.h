#ifndef SHAREDSTYLE_H
#define SHAREDSTYLE_H

#include "basecontainer.h"

class QJsonObject;

class Style;

class SharedStyle : public BaseContainer
{
    Q_OBJECT

public:
    explicit SharedStyle(QObject *parent = Q_NULLPTR);
    explicit SharedStyle(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    const QString &name() const;
    const Style *value() const;

private:
    QString m_do_objectID;
    QString m_name;
    Style *m_value;
};

#endif // SHAREDSTYLE_H
