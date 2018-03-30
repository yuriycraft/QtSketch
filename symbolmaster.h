#ifndef SYMBOLMASTER_H
#define SYMBOLMASTER_H

#include "basecontainer.h"

class QJsonObject;

class Color;
class ExportOptions;
class Rect;
class RulerData;
class Style;

class SymbolMaster : public BaseContainer
{
    Q_OBJECT

public:
    explicit SymbolMaster(QObject *parent = Q_NULLPTR);
    explicit SymbolMaster(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

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
    //TODO layers
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
