#ifndef SYMBOLINSTANCE_H
#define SYMBOLINSTANCE_H

#include "layer.h"

class QJsonObject;

class SymbolInstance : public Layer
{
    Q_OBJECT
    Q_PROPERTY(bool nameIsFixed READ nameIsFixed CONSTANT)
    //TODO overrideValues
    //TODO overrides
    Q_PROPERTY(double resizingConstraint READ resizingConstraint CONSTANT)
    Q_PROPERTY(double resizingType READ resizingType CONSTANT)
    Q_PROPERTY(double scale READ scale CONSTANT)
    Q_PROPERTY(bool shouldBreakMaskChain READ shouldBreakMaskChain CONSTANT)
    Q_PROPERTY(QString symbolID READ symbolID CONSTANT)
    Q_PROPERTY(double verticalSpacing READ verticalSpacing CONSTANT)
    Q_PROPERTY(double horizontalSpacing READ horizontalSpacing CONSTANT)
    Q_PROPERTY(double layerListExpandedType READ layerListExpandedType CONSTANT)
    Q_PROPERTY(double masterInfluenceEdgeMaxXPadding READ masterInfluenceEdgeMaxXPadding CONSTANT)
    Q_PROPERTY(double masterInfluenceEdgeMaxYPadding READ masterInfluenceEdgeMaxYPadding CONSTANT)
    Q_PROPERTY(double masterInfluenceEdgeMinXPadding READ masterInfluenceEdgeMinXPadding CONSTANT)
    Q_PROPERTY(double masterInfluenceEdgeMinYPadding READ masterInfluenceEdgeMinYPadding CONSTANT)

public:
    Q_INVOKABLE explicit SymbolInstance(QObject *parent = Q_NULLPTR);

    bool nameIsFixed() const;
    //TODO overrideValues
    //TODO overrides
    double resizingConstraint() const;
    double resizingType() const;
    double scale() const;
    bool shouldBreakMaskChain() const;
    const QString &symbolID() const;
    double verticalSpacing() const;
    double horizontalSpacing() const;
    double layerListExpandedType() const;
    double masterInfluenceEdgeMaxXPadding() const;
    double masterInfluenceEdgeMaxYPadding() const;
    double masterInfluenceEdgeMinXPadding() const;
    double masterInfluenceEdgeMinYPadding() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    bool m_nameIsFixed;
    //TODO m_overrideValues;
    //TODO m_overrides;
    double m_resizingConstraint;
    double m_resizingType;
    double m_scale;
    bool m_shouldBreakMaskChain;
    QString m_symbolID;
    double m_verticalSpacing;
    double m_horizontalSpacing;
    double m_layerListExpandedType;
    double m_masterInfluenceEdgeMaxXPadding;
    double m_masterInfluenceEdgeMaxYPadding;
    double m_masterInfluenceEdgeMinXPadding;
    double m_masterInfluenceEdgeMinYPadding;
};

#endif // SYMBOLINSTANCE_H
