#ifndef LAYER_H
#define LAYER_H

#include "basecontainer.h"

class Rect;
class Style;
class ExportOptions;

class Layer : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(bool nameIsFixed READ nameIsFixed CONSTANT)
    Q_PROPERTY(Rect* frame READ frame CONSTANT)
    Q_PROPERTY(bool isFlippedVertical READ isFlippedVertical CONSTANT)
    Q_PROPERTY(bool isFlippedHorizontal READ isFlippedHorizontal CONSTANT)
    Q_PROPERTY(bool isVisible READ isVisible CONSTANT)
    Q_PROPERTY(ResizingConstraint resizingConstraints READ resizingConstraints CONSTANT)
    Q_PROPERTY(double rotation READ rotation CONSTANT)
    Q_PROPERTY(Style* style READ style CONSTANT)
    Q_PROPERTY(ExportOptions* exportOptions READ exportOptions CONSTANT)
    Q_PROPERTY(bool isLocked READ isLocked CONSTANT)
    Q_PROPERTY(double resizingConstraint READ resizingConstraint CONSTANT)
    Q_PROPERTY(double resizingType READ resizingType CONSTANT)
    Q_PROPERTY(bool shouldBreakMaskChain READ shouldBreakMaskChain CONSTANT)
    Q_PROPERTY(double layerListExpandedType READ layerListExpandedType CONSTANT)

protected:
    explicit Layer(QObject *parent = Q_NULLPTR);

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
    bool nameIsFixed() const;
    Rect *frame() const;
    bool isFlippedVertical() const;
    bool isFlippedHorizontal() const;
    bool isVisible() const;
    ResizingConstraint resizingConstraints() const;
    double rotation() const;
    Style *style() const;
    ExportOptions *exportOptions() const;
    bool isLocked() const;
    double resizingConstraint() const;
    double resizingType() const;
    bool shouldBreakMaskChain() const;
    double layerListExpandedType() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QString m_do_objectID;
    QString m_name;
    bool m_nameIsFixed;
    Rect *m_frame;
    bool m_isFlippedVertical;
    bool m_isFlippedHorizontal;
    bool m_isVisible;
    ResizingConstraint m_resizingConstraints;
    double m_rotation;
    Style *m_style;
    ExportOptions *m_exportOptions;
    bool m_isLocked;
    double m_resizingConstraint;
    double m_resizingType;
    bool m_shouldBreakMaskChain;
    double m_layerListExpandedType;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Layer::ResizingConstraints)

#endif // LAYER_H
