#include "fill.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

#include "utils.h"

#include "color.h"
#include "graphicscontextsettings.h"
#include "msjsonfilereference.h"
#include "gradient.h"

Fill::Fill(QObject *parent) :
    BaseContainer(parent),
    m_color(Q_NULLPTR),
    m_fillType(0.),
    m_gradient(Q_NULLPTR)
{

}

Fill::Fill(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_color(Q_NULLPTR),
    m_fillType(0.),
    m_gradient(Q_NULLPTR)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("color"))
        {
            Q_ASSERT(iter.value().isObject());
            m_color = createContainer<Color>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("contextSettings"))
        {
            Q_ASSERT(iter.value().isObject());
            m_contextSettings = createContainer<GraphicsContextSettings>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("fillType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_fillType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("image"))
        {
            Q_ASSERT(iter.value().isObject());
            m_image = createContainer<MSJSONFileReference>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("gradient"))
        {
            Q_ASSERT(iter.value().isObject());
            m_gradient = createContainer<Gradient>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("isEnabled"))
        {
            Q_ASSERT(iter.value().isBool());
            m_isEnabled = iter.value().toBool();
        }
        else if(iter.key() == QStringLiteral("noiseIndex"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_noiseIndex = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("noiseIntensity"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_noiseIntensity = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("patternFillType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_patternFillType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("patternTileScale"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_patternTileScale = iter.value().toDouble();
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

const Color *Fill::color() const
{
    return m_color;
}

const GraphicsContextSettings *Fill::contextSettings() const
{
    return m_contextSettings;
}

double Fill::fillType() const
{
    return m_fillType;
}

const MSJSONFileReference *Fill::image() const
{
    return m_image;
}

const Gradient *Fill::gradient() const
{
    return m_gradient;
}

bool Fill::isEnabled() const
{
    return m_isEnabled;
}

double Fill::noiseIndex() const
{
    return m_noiseIndex;
}

double Fill::noiseIntensity() const
{
    return m_noiseIntensity;
}

double Fill::patternFillType() const
{
    return m_patternFillType;
}

double Fill::patternTileScale() const
{
    return m_patternTileScale;
}
