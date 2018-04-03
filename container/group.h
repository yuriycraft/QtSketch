#ifndef GROUP_H
#define GROUP_H

#include "layer.h"

class QJsonObject;

class Layer;

class Group : public Layer
{
    Q_OBJECT
    Q_PROPERTY(QList<Layer*> layers READ layers CONSTANT)
    Q_PROPERTY(bool hasClickThrough READ hasClickThrough CONSTANT)

public:
    Q_INVOKABLE explicit Group(QObject *parent = Q_NULLPTR);

    const QList<Layer*> &layers() const;
    bool hasClickThrough() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QList<Layer*> m_layers;
    bool m_hasClickThrough;
};

#endif // GROUP_H
