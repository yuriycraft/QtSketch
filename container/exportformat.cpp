#include "exportformat.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

ExportFormat::ExportFormat(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

double ExportFormat::absoluteSize() const
{
    return m_absoluteSize;
}

const QString &ExportFormat::fileFormat() const
{
    return m_fileFormat;
}

const QString &ExportFormat::name() const
{
    return m_name;
}

double ExportFormat::namingScheme() const
{
    return m_namingScheme;
}

double ExportFormat::scale() const
{
    return m_scale;
}

double ExportFormat::visibleScaleType() const
{
    return m_visibleScaleType;
}

bool ExportFormat::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("absoluteSize"))
    {
        Q_ASSERT(value.isDouble());
        m_absoluteSize = value.toDouble();
    }

    if(key == QStringLiteral("fileFormat"))
    {
        Q_ASSERT(value.isString());
        m_fileFormat = value.toString();
    }

    if(key == QStringLiteral("name"))
    {
        Q_ASSERT(value.isString());
        m_name = value.toString();
    }

    if(key == QStringLiteral("namingScheme"))
    {
        Q_ASSERT(value.isDouble());
        m_namingScheme = value.toDouble();
    }

    if(key == QStringLiteral("scale"))
    {
        Q_ASSERT(value.isDouble());
        m_scale = value.toDouble();
    }

    if(key == QStringLiteral("visibleScaleType"))
    {
        Q_ASSERT(value.isDouble());
        m_visibleScaleType = value.toDouble();
    }

    return BaseContainer::parseProperty(key, value);
}
