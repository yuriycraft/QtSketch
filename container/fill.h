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

public:
    explicit Fill(QObject *parent = Q_NULLPTR);
    explicit Fill(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const Color *color() const;
    const GraphicsContextSettings *contextSettings() const;
    double fillType() const;
    const MSJSONFileReference *image() const;
    const Gradient *gradient() const;
    bool isEnabled() const;
    double noiseIndex() const;
    double noiseIntensity() const;
    double patternFillType() const;
    double patternTileScale() const;

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
