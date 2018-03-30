#include "style.h"

#include <QDebug>

Style::Style(QObject *parent) :
    BaseContainer(parent)
{
}

Style::Style(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
