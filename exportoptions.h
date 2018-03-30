#ifndef EXPORTOPTIONS_H
#define EXPORTOPTIONS_H

#include "basecontainer.h"

class QJsonObject;

class ExportOptions : public BaseContainer
{
    Q_OBJECT

public:
    explicit ExportOptions(QObject *parent = Q_NULLPTR);
    explicit ExportOptions(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
};

#endif // EXPORTOPTIONS_H
