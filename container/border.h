#pragma once

#include "basecontainer.h"

class QJsonObject;

class Color;

class Border : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(Color* color READ color CONSTANT)
    Q_PROPERTY(FillType fillType READ fillType CONSTANT)
    Q_PROPERTY(bool isEnabled READ isEnabled CONSTANT)
    Q_PROPERTY(Position position READ position CONSTANT)
    Q_PROPERTY(double thickness READ thickness CONSTANT)

public:
    Q_INVOKABLE explicit Border(QObject *parent = Q_NULLPTR);

    enum class FillType {
        FlatColor = 0,
        LinearGradient = 1,
        RadialGradient = 2,
        AngularGradient = 3
    };
    Q_ENUM(FillType)

    enum class Position {
        Inside = 0,
        Center = 1,
        Outside = 2
    };
    Q_ENUM(Position)

    Color *color() const;
    FillType fillType() const;
    bool isEnabled() const;
    Position position() const;
    double thickness() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    Color *m_color;
    FillType m_fillType;
    bool m_isEnabled;
    Position m_position;
    double m_thickness;
};
