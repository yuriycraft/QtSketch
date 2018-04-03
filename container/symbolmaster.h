#ifndef SYMBOLMASTER_H
#define SYMBOLMASTER_H

#include "artboard.h"

class QJsonObject;

class Color;
class RulerData;

class SymbolMaster : public Artboard
{
    Q_OBJECT
    Q_PROPERTY(Color* backgroundColor READ backgroundColor CONSTANT)
    Q_PROPERTY(double changeIdentifier READ changeIdentifier CONSTANT)
    Q_PROPERTY(bool hasBackgroundColor READ hasBackgroundColor CONSTANT)
    Q_PROPERTY(bool hasClickThrough READ hasClickThrough CONSTANT)
    Q_PROPERTY(RulerData* horizontalRulerData READ horizontalRulerData CONSTANT)
    Q_PROPERTY(bool includeBackgroundColorInExport READ includeBackgroundColorInExport CONSTANT)
    Q_PROPERTY(bool includeBackgroundColorInInstance READ includeBackgroundColorInInstance CONSTANT)
    Q_PROPERTY(bool includeInCloudUpload READ includeInCloudUpload CONSTANT)
    Q_PROPERTY(bool isFlowHome READ isFlowHome CONSTANT)
    Q_PROPERTY(double layerListExpandedType READ layerListExpandedType CONSTANT)
    Q_PROPERTY(bool nameIsFixed READ nameIsFixed CONSTANT)
    Q_PROPERTY(bool resizesContent READ resizesContent CONSTANT)
    Q_PROPERTY(double resizingConstraint READ resizingConstraint CONSTANT)
    Q_PROPERTY(double resizingType READ resizingType CONSTANT)
    Q_PROPERTY(bool shouldBreakMaskChain READ shouldBreakMaskChain CONSTANT)
    Q_PROPERTY(QString symbolID READ symbolID CONSTANT)
    Q_PROPERTY(RulerData* verticalRulerData READ verticalRulerData CONSTANT)

public:
    Q_INVOKABLE explicit SymbolMaster(QObject *parent = Q_NULLPTR);

    Color *backgroundColor() const;
    double changeIdentifier() const;
    bool hasBackgroundColor() const;
    bool hasClickThrough() const;
    RulerData *horizontalRulerData() const;
    bool includeBackgroundColorInExport() const;
    bool includeBackgroundColorInInstance() const;
    bool includeInCloudUpload() const;
    bool isFlowHome() const;
    double layerListExpandedType() const;
    bool nameIsFixed() const;
    bool resizesContent() const;
    double resizingConstraint() const;
    double resizingType() const;
    bool shouldBreakMaskChain() const;
    const QString &symbolID() const;
    RulerData *verticalRulerData() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    Color *m_backgroundColor;
    double m_changeIdentifier;
    bool m_hasBackgroundColor;
    bool m_hasClickThrough;
    RulerData *m_horizontalRulerData;
    bool m_includeBackgroundColorInExport;
    bool m_includeBackgroundColorInInstance;
    bool m_includeInCloudUpload;
    bool m_isFlowHome;
    double m_layerListExpandedType;
    bool m_nameIsFixed;
    bool m_resizesContent;
    double m_resizingConstraint;
    double m_resizingType;
    bool m_shouldBreakMaskChain;
    QString m_symbolID;
    RulerData *m_verticalRulerData;
};

#endif // SYMBOLMASTER_H
