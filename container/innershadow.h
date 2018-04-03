#ifndef INNERSHADOW_H
#define INNERSHADOW_H

#include "basecontainer.h"

class Color;
class GraphicsContextSettings;

class InnerShadow : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(bool isEnabled READ isEnabled CONSTANT)
    Q_PROPERTY(double blurRadius READ blurRadius CONSTANT)
    Q_PROPERTY(Color* color READ color CONSTANT)
    Q_PROPERTY(GraphicsContextSettings* contextSettings READ contextSettings CONSTANT)
    Q_PROPERTY(double offsetX READ offsetX CONSTANT)
    Q_PROPERTY(double offsetY READ offsetY CONSTANT)
    Q_PROPERTY(double spread READ spread CONSTANT)

public:
    Q_INVOKABLE explicit InnerShadow(QObject *parent = Q_NULLPTR);

    bool isEnabled() const;
    double blurRadius() const;
    Color *color() const;
    GraphicsContextSettings *contextSettings() const;
    double offsetX() const;
    double offsetY() const;
    double spread() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    bool m_isEnabled;
    double m_blurRadius;
    Color *m_color;
    GraphicsContextSettings *m_contextSettings;
    double m_offsetX;
    double m_offsetY;
    double m_spread;
};

#endif // INNERSHADOW_H
