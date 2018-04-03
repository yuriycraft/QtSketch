#ifndef PAGE_H
#define PAGE_H

#include "group.h"

class QJsonObject;

class ExportOptions;
class Rect;
class Style;
class SymbolMaster;
class RulerData;

class Page : public Group
{
    Q_OBJECT
    Q_PROPERTY(ExportOptions* exportOptions READ exportOptions CONSTANT)
    Q_PROPERTY(bool isLocked READ isLocked CONSTANT)
    Q_PROPERTY(double layerListExpandedType READ layerListExpandedType CONSTANT)
    Q_PROPERTY(bool nameIsFixed READ nameIsFixed CONSTANT)
    Q_PROPERTY(double resizingConstraint READ resizingConstraint CONSTANT)
    Q_PROPERTY(double resizingType READ resizingType CONSTANT)
    Q_PROPERTY(bool shouldBreakMaskChain READ shouldBreakMaskChain CONSTANT)
    Q_PROPERTY(bool hasClickThrough READ hasClickThrough CONSTANT)
    Q_PROPERTY(RulerData* horizontalRulerData READ horizontalRulerData CONSTANT)
    Q_PROPERTY(bool includeInCloudUpload READ includeInCloudUpload CONSTANT)
    Q_PROPERTY(RulerData* verticalRulerData READ verticalRulerData CONSTANT)

public:
    Q_INVOKABLE explicit Page(QObject *parent = Q_NULLPTR);

    ExportOptions *exportOptions() const;
    bool isLocked() const;
    double layerListExpandedType() const;
    bool nameIsFixed() const;
    double resizingConstraint() const;
    double resizingType() const;
    bool shouldBreakMaskChain() const;
    bool hasClickThrough() const;
    RulerData *horizontalRulerData() const;
    bool includeInCloudUpload() const;
    RulerData *verticalRulerData() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    ExportOptions *m_exportOptions;
    bool m_isLocked;
    double m_layerListExpandedType;
    bool m_nameIsFixed;
    double m_resizingConstraint;
    double m_resizingType;
    bool m_shouldBreakMaskChain;
    bool m_hasClickThrough;
    RulerData *m_horizontalRulerData;
    bool m_includeInCloudUpload;
    RulerData *m_verticalRulerData;
};

#endif // PAGE_H
