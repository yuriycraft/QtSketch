#include "fill.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

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

Color *Fill::color() const
{
    return m_color;
}

GraphicsContextSettings *Fill::contextSettings() const
{
    return m_contextSettings;
}

double Fill::fillType() const
{
    return m_fillType;
}

MSJSONFileReference *Fill::image() const
{
    return m_image;
}

Gradient *Fill::gradient() const
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

bool Fill::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("color"))
    {
        Q_ASSERT(value.isObject());
        m_color = ContainerFactory::createContainer<Color>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("contextSettings"))
    {
        Q_ASSERT(value.isObject());
        m_contextSettings = ContainerFactory::createContainer<GraphicsContextSettings>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("fillType"))
    {
        Q_ASSERT(value.isDouble());
        m_fillType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("image"))
    {
        Q_ASSERT(value.isObject());
        m_image = ContainerFactory::createContainer<MSJSONFileReference>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("gradient"))
    {
        Q_ASSERT(value.isObject());
        m_gradient = ContainerFactory::createContainer<Gradient>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("isEnabled"))
    {
        Q_ASSERT(value.isBool());
        m_isEnabled = value.toBool();
        return true;
    }

    if(key == QStringLiteral("noiseIndex"))
    {
        Q_ASSERT(value.isDouble());
        m_noiseIndex = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("noiseIntensity"))
    {
        Q_ASSERT(value.isDouble());
        m_noiseIntensity = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("patternFillType"))
    {
        Q_ASSERT(value.isDouble());
        m_patternFillType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("patternTileScale"))
    {
        Q_ASSERT(value.isDouble());
        m_patternTileScale = value.toDouble();
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
