#ifndef SYMBOLMASTER_H
#define SYMBOLMASTER_H

#include "basecontainer.h"

class QJsonObject;

class Color;
class ExportOptions;
class Rect;
class RulerData;
class Group;
class Style;

class SymbolMaster : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(Color* backgroundColor READ backgroundColor CONSTANT)
    Q_PROPERTY(double changeIdentifier READ changeIdentifier CONSTANT)
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(ExportOptions* exportOptions READ exportOptions CONSTANT)
    Q_PROPERTY(Rect* frame READ frame CONSTANT)
    Q_PROPERTY(bool hasBackgroundColor READ hasBackgroundColor CONSTANT)
    Q_PROPERTY(bool hasClickThrough READ hasClickThrough CONSTANT)
    Q_PROPERTY(RulerData* horizontalRulerData READ horizontalRulerData CONSTANT)
    Q_PROPERTY(bool includeBackgroundColorInExport READ includeBackgroundColorInExport CONSTANT)
    Q_PROPERTY(bool includeBackgroundColorInInstance READ includeBackgroundColorInInstance CONSTANT)
    Q_PROPERTY(bool includeInCloudUpload READ includeInCloudUpload CONSTANT)
    Q_PROPERTY(bool isFlippedHorizontal READ isFlippedHorizontal CONSTANT)
    Q_PROPERTY(bool isFlippedVertical READ isFlippedVertical CONSTANT)
    Q_PROPERTY(bool isFlowHome READ isFlowHome CONSTANT)
    Q_PROPERTY(bool isLocked READ isLocked CONSTANT)
    Q_PROPERTY(bool isVisible READ isVisible CONSTANT)
    Q_PROPERTY(double layerListExpandedType READ layerListExpandedType CONSTANT)
    Q_PROPERTY(QList<Group*> layers READ layers CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(bool nameIsFixed READ nameIsFixed CONSTANT)
    Q_PROPERTY(bool resizesContent READ resizesContent CONSTANT)
    Q_PROPERTY(double resizingConstraint READ resizingConstraint CONSTANT)
    Q_PROPERTY(double resizingType READ resizingType CONSTANT)
    Q_PROPERTY(double rotation READ rotation CONSTANT)
    Q_PROPERTY(bool shouldBreakMaskChain READ shouldBreakMaskChain CONSTANT)
    Q_PROPERTY(Style* style READ style CONSTANT)
    Q_PROPERTY(QString symbolID READ symbolID CONSTANT)
    Q_PROPERTY(RulerData* verticalRulerData READ verticalRulerData CONSTANT)

public:
    Q_INVOKABLE explicit SymbolMaster(QObject *parent = Q_NULLPTR);
    Q_INVOKABLE explicit SymbolMaster(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    Color *backgroundColor() const;
    double changeIdentifier() const;
    const QString &do_objectID() const;
    ExportOptions *exportOptions() const;
    Rect *frame() const;
    bool hasBackgroundColor() const;
    bool hasClickThrough() const;
    RulerData *horizontalRulerData() const;
    bool includeBackgroundColorInExport() const;
    bool includeBackgroundColorInInstance() const;
    bool includeInCloudUpload() const;
    bool isFlippedHorizontal() const;
    bool isFlippedVertical() const;
    bool isFlowHome() const;
    bool isLocked() const;
    bool isVisible() const;
    double layerListExpandedType() const;
    const QList<Group*> &layers() const;
    const QString &name() const;
    bool nameIsFixed() const;
    bool resizesContent() const;
    double resizingConstraint() const;
    double resizingType() const;
    double rotation() const;
    bool shouldBreakMaskChain() const;
    Style *style() const;
    const QString &symbolID() const;
    RulerData *verticalRulerData() const;

private:
    Color *m_backgroundColor;
    double m_changeIdentifier;
    QString m_do_objectID;
    ExportOptions *m_exportOptions;
    Rect *m_frame;
    bool m_hasBackgroundColor;
    bool m_hasClickThrough;
    RulerData *m_horizontalRulerData;
    bool m_includeBackgroundColorInExport;
    bool m_includeBackgroundColorInInstance;
    bool m_includeInCloudUpload;
    bool m_isFlippedHorizontal;
    bool m_isFlippedVertical;
    bool m_isFlowHome;
    bool m_isLocked;
    bool m_isVisible;
    double m_layerListExpandedType;
    QList<Group*> m_layers;
    QString m_name;
    bool m_nameIsFixed;
    bool m_resizesContent;
    double m_resizingConstraint;
    double m_resizingType;
    double m_rotation;
    bool m_shouldBreakMaskChain;
    Style *m_style;
    QString m_symbolID;
    RulerData *m_verticalRulerData;
};

#endif // SYMBOLMASTER_H
