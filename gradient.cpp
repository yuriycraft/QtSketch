#include "gradient.h"

#include <QDebug>

Gradient::Gradient(QObject *parent) :
    BaseContainer(parent)
{
}

Gradient::Gradient(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
