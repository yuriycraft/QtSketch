#include "textstyle.h"

#include <QDebug>

TextStyle::TextStyle(QObject *parent) :
    BaseContainer(parent)
{
}

TextStyle::TextStyle(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
