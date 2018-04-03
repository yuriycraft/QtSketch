#ifndef LAYER_H
#define LAYER_H

#include "basecontainer.h"

class Rect;
class Style;

class Layer : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(Rect* frame READ frame CONSTANT)
    Q_PROPERTY(bool isFlippedVertical READ isFlippedVertical CONSTANT)
    Q_PROPERTY(bool isFlippedHorizontal READ isFlippedHorizontal CONSTANT)
    Q_PROPERTY(bool isVisible READ isVisible CONSTANT)
    Q_PROPERTY(ResizingConstraint resizingConstraints READ resizingConstraints CONSTANT)
    Q_PROPERTY(double rotation READ rotation CONSTANT)
    Q_PROPERTY(Style* style READ style CONSTANT)

protected:
    explicit Layer(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

public:
    enum ResizingConstraint
    {
        None = 0,
        FlexibleRightMargin = 1,
        FlexibleWidth = 2,
        FlexibleLeftMargin = 4,
        FlexibleBottomMargin = 8,
        FlexibleHeight = 16,
        FlexibleTopMargin = 32
    };
    Q_DECLARE_FLAGS(ResizingConstraints, ResizingConstraint)
    Q_FLAG(ResizingConstraints)

    const QString &do_objectID() const;
    const QString &name() const;
    Rect *frame() const;
    bool isFlippedVertical() const;
    bool isFlippedHorizontal() const;
    bool isVisible() const;
    ResizingConstraint resizingConstraints() const;
    double rotation() const;
    Style *style() const;

private:
    QString m_do_objectID;
    QString m_name;
    Rect *m_frame;
    bool m_isFlippedVertical;
    bool m_isFlippedHorizontal;
    bool m_isVisible;
    ResizingConstraint m_resizingConstraints;
    double m_rotation;
    Style *m_style;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Layer::ResizingConstraints)

#endif // LAYER_H
