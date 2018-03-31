#ifndef BORDER_H
#define BORDER_H

#include "basecontainer.h"

class QJsonObject;

class Color;

class Border : public BaseContainer
{
    Q_OBJECT

public:
    explicit Border(QObject *parent = Q_NULLPTR);
    explicit Border(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const Color *color() const;
    double fillType() const;
    bool isEnabled() const;
    double position() const;
    double thickness() const;

private:
    Color *m_color;
    double m_fillType;
    bool m_isEnabled;
    double m_position;
    double m_thickness;
};

#endif // BORDER_H
