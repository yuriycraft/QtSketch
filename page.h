#ifndef PAGE_H
#define PAGE_H

#include "basecontainer.h"

class QJsonObject;

class ExportOptions;
class Rect;
class Style;
class RulerData;

class Page : public BaseContainer
{
    Q_OBJECT

public:
    explicit Page(QObject *parent = Q_NULLPTR);
    explicit Page(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

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
    //TODO layers
    RulerData *m_horizontalRulerData;
    bool m_includeInCloudUpload;
    RulerData *m_verticalRulerData;
};

#endif // PAGE_H
