#ifndef GRADIENTSTOP_H
#define GRADIENTSTOP_H

#include "basecontainer.h"

class QJsonObject;

class Color;

class GradientStop : public BaseContainer
{
    Q_OBJECT

public:
    explicit GradientStop(QObject *parent = Q_NULLPTR);
    explicit GradientStop(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const Color *color() const;
    double position() const;

private:
    Color *m_color;
    double m_position;
};

#endif // GRADIENTSTOP_H
