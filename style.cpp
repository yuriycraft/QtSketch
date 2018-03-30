#include "style.h"

Style::Style(QObject *parent) :
    BaseContainer(parent)
{
}

Style::Style(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
}
