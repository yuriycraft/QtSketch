#include "fill.h"

#include <QDebug>

Fill::Fill(QObject *parent) :
    BaseContainer(parent)
{

}

Fill::Fill(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
    //TODO
    qWarning() << "not implemented";
}
