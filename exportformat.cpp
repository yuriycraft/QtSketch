#include "exportformat.h"

#include <QDebug>

ExportFormat::ExportFormat(QObject *parent) :
    BaseContainer(parent)
{
}

ExportFormat::ExportFormat(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qDebug() << "not implemented";
}
