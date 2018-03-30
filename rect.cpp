#include "rect.h"

#include <QDebug>

Rect::Rect(QObject *parent) :
    BaseContainer(parent)
{
}

Rect::Rect(const QJsonObject &jsonObj, QObject *parent)
{
    //TODO
    qWarning() << "not implemented";
}
