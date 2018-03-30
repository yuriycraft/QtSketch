#ifndef RECT_H
#define RECT_H

#include "basecontainer.h"

class QJsonObject;

class Rect : public BaseContainer
{
    Q_OBJECT

public:
    explicit Rect(QObject *parent = Q_NULLPTR);
    explicit Rect(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    bool constrainProportions() const;
    double height() const;
    double width() const;
    double x() const;
    double y() const;

private:
    bool m_constrainProportions;
    double m_height;
    double m_width;
    double m_x;
    double m_y;
};

#endif // RECT_H
