#ifndef MSJSONFILEREFERENCE_H
#define MSJSONFILEREFERENCE_H

#include "basecontainer.h"

class QJsonObject;

class MSJSONFileReference : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString _ref READ _ref CONSTANT)
    Q_PROPERTY(QString _ref_class READ _ref_class CONSTANT)

public:
    Q_INVOKABLE explicit MSJSONFileReference(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &_ref() const;
    const QString &_ref_class() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QString m__ref;
    QString m__ref_class;
};

#endif // MSJSONFILEREFERENCE_H
