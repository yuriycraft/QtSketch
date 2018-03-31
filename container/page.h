#ifndef PAGE_H
#define PAGE_H

#include "basecontainer.h"

class QJsonObject;

class ExportOptions;
class Rect;
class Style;
class SymbolMaster;
class RulerData;

class Page : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(ExportOptions* exportOptions READ exportOptions CONSTANT)
    Q_PROPERTY(Rect* frame READ frame CONSTANT)
    Q_PROPERTY(bool isFlippedHorizontal READ isFlippedHorizontal CONSTANT)
    Q_PROPERTY(bool isFlippedVertical READ isFlippedVertical CONSTANT)
    Q_PROPERTY(bool isLocked READ isLocked CONSTANT)
    Q_PROPERTY(bool isVisible READ isVisible CONSTANT)
    Q_PROPERTY(double layerListExpandedType READ layerListExpandedType CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(bool nameIsFixed READ nameIsFixed CONSTANT)
    Q_PROPERTY(double resizingConstraint READ resizingConstraint CONSTANT)
    Q_PROPERTY(double resizingType READ resizingType CONSTANT)
    Q_PROPERTY(double rotation READ rotation CONSTANT)
    Q_PROPERTY(bool shouldBreakMaskChain READ shouldBreakMaskChain CONSTANT)
    Q_PROPERTY(Style* style READ style CONSTANT)
    Q_PROPERTY(bool hasClickThrough READ hasClickThrough CONSTANT)
    Q_PROPERTY(QList<SymbolMaster*> layers READ layers CONSTANT)
    Q_PROPERTY(RulerData* horizontalRulerData READ horizontalRulerData CONSTANT)
    Q_PROPERTY(bool includeInCloudUpload READ includeInCloudUpload CONSTANT)
    Q_PROPERTY(RulerData* verticalRulerData READ verticalRulerData CONSTANT)

public:
    explicit Page(QObject *parent = Q_NULLPTR);
    explicit Page(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    ExportOptions *exportOptions() const;
    Rect *frame() const;
    bool isFlippedHorizontal() const;
    bool isFlippedVertical() const;
    bool isLocked() const;
    bool isVisible() const;
    double layerListExpandedType() const;
    const QString &name() const;
    bool nameIsFixed() const;
    double resizingConstraint() const;
    double resizingType() const;
    double rotation() const;
    bool shouldBreakMaskChain() const;
    Style *style() const;
    bool hasClickThrough() const;
    const QList<SymbolMaster*> &layers() const;
    RulerData *horizontalRulerData() const;
    bool includeInCloudUpload() const;
    RulerData *verticalRulerData() const;

private:
    QString m_do_objectID;
    ExportOptions *m_exportOptions;
    Rect *m_frame;
    bool m_isFlippedHorizontal;
    bool m_isFlippedVertical;
    bool m_isLocked;
    bool m_isVisible;
    double m_layerListExpandedType;
    QString m_name;
    bool m_nameIsFixed;
    double m_resizingConstraint;
    double m_resizingType;
    double m_rotation;
    bool m_shouldBreakMaskChain;
    Style *m_style;
    bool m_hasClickThrough;
    QList<SymbolMaster*> m_layers;
    RulerData *m_horizontalRulerData;
    bool m_includeInCloudUpload;
    RulerData *m_verticalRulerData;
};

#endif // PAGE_H
