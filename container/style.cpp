#include "style.h"

#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>

#include "utils.h"

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

Style::Style(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent),
    m_blur(Q_NULLPTR),
    m_borderOptions(Q_NULLPTR),
    m_miterLimit(0.),
    m_startDecorationType(0.),
    m_textStyle(Q_NULLPTR)
{
    for(auto iter = jsonObj.constBegin(); iter != jsonObj.constEnd(); iter++)
    {
        if(iter.key() == QStringLiteral("_class"))
            continue;
        else if(iter.key() == QStringLiteral("do_objectID"))
        {
            Q_ASSERT(iter.value().isString());
            m_do_objectID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("name"))
        {
            Q_ASSERT(iter.value().isString());
            m_name = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("blur"))
        {
            Q_ASSERT(iter.value().isObject());
            m_blur = createContainer<Blur>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("borderOptions"))
        {
            Q_ASSERT(iter.value().isObject());
            m_borderOptions = createContainer<BorderOptions>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("borders"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto fillValue : iter.value().toArray())
            {
                Q_ASSERT(fillValue.isObject());
                m_borders.append(createContainer<Border>(fillValue.toObject(), this));
            }
        }
        else if(iter.key() == QStringLiteral("fills"))
        {
            Q_ASSERT(iter.value().isArray());
            for(auto fillValue : iter.value().toArray())
            {
                Q_ASSERT(fillValue.isObject());
                m_fills.append(createContainer<Fill>(fillValue.toObject(), this));
            }
        }
        else if(iter.key() == QStringLiteral("contextSettings"))
        {
            Q_ASSERT(iter.value().isObject());
            m_contextSettings = createContainer<GraphicsContextSettings>(iter.value().toObject(), this);
        }
        else if(iter.key() == QStringLiteral("endDecorationType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_endDecorationType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("miterLimit"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_miterLimit = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("sharedObjectID"))
        {
            Q_ASSERT(iter.value().isString());
            m_sharedObjectID = iter.value().toString();
        }
        else if(iter.key() == QStringLiteral("startDecorationType"))
        {
            Q_ASSERT(iter.value().isDouble());
            m_startDecorationType = iter.value().toDouble();
        }
        else if(iter.key() == QStringLiteral("textStyle"))
        {
            Q_ASSERT(iter.value().isObject());
            m_textStyle = createContainer<TextStyle>(iter.value().toObject(), this);
        }
        else
            qWarning() << "unexpected" << iter.key();
    }
}

const QString &Style::do_objectID() const
{
    return m_do_objectID;
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
