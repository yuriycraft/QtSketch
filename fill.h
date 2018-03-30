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
