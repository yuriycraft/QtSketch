#include "gradientstop.h"

GradientStop::GradientStop(QObject *parent) :
    BaseContainer(parent)
{
}

GradientStop::GradientStop(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{
}

const Color *GradientStop::color() const
{
    return m_color;
}

double GradientStop::position() const
{
    return m_position;
}
