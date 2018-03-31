#include "artboard.h"

#include <QDebug>

Artboard::Artboard(QObject *parent) :
    BaseContainer(parent)
{
}

Artboard::Artboard(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
