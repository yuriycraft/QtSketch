#include "text.h"

#include <QDebug>

Text::Text(QObject *parent) :
    BaseContainer(parent)
{
}

Text::Text(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
