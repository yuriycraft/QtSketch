#ifndef EXPORTOPTIONS_H
#define EXPORTOPTIONS_H

#include "basecontainer.h"

class QJsonObject;

class ExportFormat;

class ExportOptions : public BaseContainer
{
    Q_OBJECT

public:
    explicit ExportOptions(QObject *parent = Q_NULLPTR);
    explicit ExportOptions(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    QList<ExportFormat*> m_exportFormats;
    //TODO includedLayerIds
    double m_layerOptions;
    bool m_shouldTrim;
};

#endif // EXPORTOPTIONS_H
