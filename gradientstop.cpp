#include "gradientstop.h"

GradientStop::GradientStop(QObject *parent) :
    BaseContainer(parent)
{
}

GradientStop::GradientStop(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
}
