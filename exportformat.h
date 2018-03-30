#ifndef EXPORTFORMAT_H
#define EXPORTFORMAT_H

#include "basecontainer.h"

class QJsonObject;

class ExportFormat : public BaseContainer
{
    Q_OBJECT

public:
    explicit ExportFormat(QObject *parent = Q_NULLPTR);
    explicit ExportFormat(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // EXPORTFORMAT_H
