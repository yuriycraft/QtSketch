#ifndef FILL_H
#define FILL_H

#include "basecontainer.h"

class QJsonObject;

class Color;
class GraphicsContextSettings;
class MSJSONFileReference;
class Gradient;

class Fill : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(Color* color READ color CONSTANT)
    Q_PROPERTY(GraphicsContextSettings* contextSettings READ contextSettings CONSTANT)
    Q_PROPERTY(double fillType READ fillType CONSTANT)
    Q_PROPERTY(MSJSONFileReference* image READ image CONSTANT)
    Q_PROPERTY(Gradient* gradient READ gradient CONSTANT)
    Q_PROPERTY(bool isEnabled READ isEnabled CONSTANT)
    Q_PROPERTY(double noiseIndex READ noiseIndex CONSTANT)
    Q_PROPERTY(double noiseIntensity READ noiseIntensity CONSTANT)
    Q_PROPERTY(double patternFillType READ patternFillType CONSTANT)
    Q_PROPERTY(double patternTileScale READ patternTileScale CONSTANT)

public:
    Q_INVOKABLE explicit Fill(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    Color *color() const;
    GraphicsContextSettings *contextSettings() const;
    double fillType() const;
    MSJSONFileReference *image() const;
    Gradient *gradient() const;
    bool isEnabled() const;
    double noiseIndex() const;
    double noiseIntensity() const;
    double patternFillType() const;
    double patternTileScale() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    Color *m_color;
    GraphicsContextSettings *m_contextSettings;
    double m_fillType;
    MSJSONFileReference *m_image;
    Gradient *m_gradient;
    bool m_isEnabled;
    double m_noiseIndex;
    double m_noiseIntensity;
    double m_patternFillType;
    double m_patternTileScale;
};

#endif // FILL_H
