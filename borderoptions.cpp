#include "borderoptions.h"

#include <QDebug>

BorderOptions::BorderOptions(QObject *parent) :
    BaseContainer(parent)
{
}

BorderOptions::BorderOptions(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
