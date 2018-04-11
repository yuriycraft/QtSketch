#pragma once

#include "basecontainer.h"

class QJsonObject;

class ExportFormat;

class ExportOptions : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QList<ExportFormat*> exportFormats READ exportFormats CONSTANT)
    //TODO includedLayerIds
    Q_PROPERTY(double layerOptions READ layerOptions CONSTANT)
    Q_PROPERTY(bool shouldTrim READ shouldTrim CONSTANT)

public:
    Q_INVOKABLE explicit ExportOptions(QObject *parent = Q_NULLPTR);

    const QList<ExportFormat*> &exportFormats() const;
    //TODO includedLayerIds
    double layerOptions() const;
    bool shouldTrim() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QList<ExportFormat*> m_exportFormats;
    //TODO includedLayerIds
    double m_layerOptions;
    bool m_shouldTrim;
};
