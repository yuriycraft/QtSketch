#include "exportoptions.h"

#include <QDebug>

ExportOptions::ExportOptions(QObject *parent) :
    BaseContainer(parent)
{
}

ExportOptions::ExportOptions(const QJsonObject &jsonObj, QObject *parent)
{
    //TODO
    qWarning() << "not implemented";
}
