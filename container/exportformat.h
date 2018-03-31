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

    double absoluteSize() const;
    const QString &fileFormat() const;
    const QString &name() const;
    double namingScheme() const;
    double scale() const;
    double visibleScaleType() const;

private:
    double m_absoluteSize;
    QString m_fileFormat;
    QString m_name;
    double m_namingScheme;
    double m_scale;
    double m_visibleScaleType;
};

#endif // EXPORTFORMAT_H
