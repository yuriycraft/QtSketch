#pragma once

#include "basecontainer.h"

class QJsonObject;

class Rect : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(bool constrainProportions READ constrainProportions CONSTANT)
    Q_PROPERTY(double height READ height CONSTANT)
    Q_PROPERTY(double width READ width CONSTANT)
    Q_PROPERTY(double x READ x CONSTANT)
    Q_PROPERTY(double y READ y CONSTANT)

public:
    Q_INVOKABLE explicit Rect(QObject *parent = Q_NULLPTR);

    bool constrainProportions() const;
    double height() const;
    double width() const;
    double x() const;
    double y() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    bool m_constrainProportions;
    double m_height;
    double m_width;
    double m_x;
    double m_y;
};
