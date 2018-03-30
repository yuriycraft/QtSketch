#include "border.h"

#include <QDebug>

Border::Border(QObject *parent) :
    BaseContainer(parent)
{
}

Border::Border(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
