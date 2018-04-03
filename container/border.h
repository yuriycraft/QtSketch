#ifndef BORDER_H
#define BORDER_H

#include "basecontainer.h"

class QJsonObject;

class Color;

class Border : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(Color* color READ color CONSTANT)
    Q_PROPERTY(double fillType READ fillType CONSTANT)
    Q_PROPERTY(bool isEnabled READ isEnabled CONSTANT)
    Q_PROPERTY(double position READ position CONSTANT)
    Q_PROPERTY(double thickness READ thickness CONSTANT)

public:
    Q_INVOKABLE explicit Border(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    Color *color() const;
    double fillType() const;
    bool isEnabled() const;
    double position() const;
    double thickness() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    Color *m_color;
    double m_fillType;
    bool m_isEnabled;
    double m_position;
    double m_thickness;
};

#endif // BORDER_H
