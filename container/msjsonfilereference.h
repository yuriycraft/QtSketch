#ifndef MSJSONFILEREFERENCE_H
#define MSJSONFILEREFERENCE_H

#include "basecontainer.h"

class QJsonObject;

class MSJSONFileReference : public BaseContainer
{
    Q_OBJECT

public:
    explicit MSJSONFileReference(QObject *parent = Q_NULLPTR);
    explicit MSJSONFileReference(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &_ref() const;
    const QString &_ref_class() const;

private:
    QString m__ref;
    QString m__ref_class;
};

#endif // MSJSONFILEREFERENCE_H
