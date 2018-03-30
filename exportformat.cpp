#include "exportformat.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

ExportFormat::ExportFormat(QObject *parent) :
    BaseContainer(parent)
{
}

ExportFormat::ExportFormat(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("absoluteSize"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_absoluteSize = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("fileFormat"))
        {
            Q_ASSERT(iter.value().isString());
            m_fileFormat = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("name"))
        {
            Q_ASSERT(iter.value().isString());
            m_name = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("namingScheme"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_namingScheme = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("scale"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_scale = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("visibleScaleType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_visibleScaleType = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
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
