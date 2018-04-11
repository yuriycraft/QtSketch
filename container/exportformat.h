#pragma once

#include "basecontainer.h"

class QJsonObject;

class ExportFormat : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(double absoluteSize READ absoluteSize CONSTANT)
    Q_PROPERTY(QString fileFormat READ fileFormat CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(double namingScheme READ namingScheme CONSTANT)
    Q_PROPERTY(double scale READ scale CONSTANT)
    Q_PROPERTY(double visibleScaleType READ visibleScaleType CONSTANT)

public:
    Q_INVOKABLE explicit ExportFormat(QObject *parent = Q_NULLPTR);

    double absoluteSize() const;
    const QString &fileFormat() const;
    const QString &name() const;
    double namingScheme() const;
    double scale() const;
    double visibleScaleType() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    double m_absoluteSize;
    QString m_fileFormat;
    QString m_name;
    double m_namingScheme;
    double m_scale;
    double m_visibleScaleType;
};
