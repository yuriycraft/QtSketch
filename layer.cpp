#include "layer.h"

Layer::Layer(QObject *parent) :
    BaseContainer(parent),
    m_frame(Q_NULLPTR),
    m_isFlippedVertical(false),
    m_isFlippedHorizontal(false),
    m_isVisible(false),
    m_resizingConstraints(ResizingConstraint::None),
    m_rotation(0.),
    m_style(Q_NULLPTR)
{
}

const QString &Layer::do_objectID() const
{
    return m_do_objectID;
}

const QString &Layer::name() const
{
    return m_name;
}

Rect *Layer::frame() const
{
    return m_frame;
}

bool Layer::isFlippedVertical() const
{
    return m_isFlippedVertical;
}

bool Layer::isFlippedHorizontal() const
{
    return m_isFlippedHorizontal;
}

bool Layer::isVisible() const
{
    return m_isVisible;
}

Layer::ResizingConstraint Layer::resizingConstraints() const
{
    return m_resizingConstraints;
}

double Layer::rotation() const
{
    return m_rotation;
}

Style *Layer::style() const
{
    return m_style;
}
