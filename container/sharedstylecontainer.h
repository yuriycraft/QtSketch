#ifndef SHAREDSTYLECONTAINER_H
#define SHAREDSTYLECONTAINER_H

#include "basecontainer.h"

class QJsonObject;

class SharedStyle;

class SharedStyleContainer : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QList<SharedStyle*> objects READ objects CONSTANT)

public:
    Q_INVOKABLE explicit SharedStyleContainer(QObject *parent = Q_NULLPTR);

    const QList<SharedStyle*> &objects() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QList<SharedStyle*> m_objects;
};

#endif // SHAREDSTYLECONTAINER_H
