#include "style.h"

#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "containerfactory.h"

#include "blur.h"
#include "borderoptions.h"
#include "border.h"
#include "fill.h"
#include "graphicscontextsettings.h"
#include "textstyle.h"

Style::Style(QObject *parent) :
    BaseContainer(parent),
    m_blur(Q_NULLPTR),
    m_borderOptions(Q_NULLPTR),
    m_miterLimit(0.),
    m_startDecorationType(0.),
    m_textStyle(Q_NULLPTR)
{
}

const QString &Style::name() const
{
    return m_name;
}

Blur *Style::blur() const
{
    return m_blur;
}

BorderOptions *Style::borderOptions() const
{
    return m_borderOptions;
}

const QList<Border *> &Style::borders() const
{
    return m_borders;
}

const QList<Fill *> &Style::fills() const
{
    return m_fills;
}

GraphicsContextSettings *Style::contextSettings() const
{
    return m_contextSettings;
}

double Style::endDecorationType() const
{
    return m_endDecorationType;
}

double Style::miterLimit() const
{
    return m_miterLimit;
}

const QString &Style::sharedObjectID() const
{
    return m_sharedObjectID;
}

double Style::startDecorationType() const
{
    return m_startDecorationType;
}

TextStyle *Style::textStyle() const
{
    return m_textStyle;
}

bool Style::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("name"))
    {
        Q_ASSERT(value.isString());
        m_name = value.toString();
        return true;
    }

    if(key == QStringLiteral("blur"))
    {
        Q_ASSERT(value.isObject());
        m_blur = ContainerFactory::createContainer<Blur>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("borderOptions"))
    {
        Q_ASSERT(value.isObject());
        m_borderOptions = ContainerFactory::createContainer<BorderOptions>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("borders"))
    {
        Q_ASSERT(value.isArray());
        for(auto fillValue : value.toArray())
        {
            Q_ASSERT(fillValue.isObject());
            m_borders.append(ContainerFactory::createContainer<Border>(fillValue.toObject(), this));
        }
        return true;
    }

    if(key == QStringLiteral("fills"))
    {
        Q_ASSERT(value.isArray());
        for(auto fillValue : value.toArray())
        {
            Q_ASSERT(fillValue.isObject());
            m_fills.append(ContainerFactory::createContainer<Fill>(fillValue.toObject(), this));
        }
        return true;
    }

    if(key == QStringLiteral("contextSettings"))
    {
        Q_ASSERT(value.isObject());
        m_contextSettings = ContainerFactory::createContainer<GraphicsContextSettings>(value.toObject(), this);
        return true;
    }

    if(key == QStringLiteral("endDecorationType"))
    {
        Q_ASSERT(value.isDouble());
        m_endDecorationType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("miterLimit"))
    {
        Q_ASSERT(value.isDouble());
        m_miterLimit = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("sharedObjectID"))
    {
        Q_ASSERT(value.isString());
        m_sharedObjectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("startDecorationType"))
    {
        Q_ASSERT(value.isDouble());
        m_startDecorationType = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("textStyle"))
    {
        Q_ASSERT(value.isObject());
        m_textStyle = ContainerFactory::createContainer<TextStyle>(value.toObject(), this);
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
