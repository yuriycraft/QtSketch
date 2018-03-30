#include "rulerdata.h"

#include <QDebug>

RulerData::RulerData(QObject *parent) :
    BaseContainer(parent)
{
}

RulerData::RulerData(const QJsonObject &jsonObj, QObject *parent)
{
    //TODO
    qWarning() << "not implemented";
}
