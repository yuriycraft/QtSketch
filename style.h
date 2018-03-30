#ifndef STYLE_H
#define STYLE_H

#include "basecontainer.h"

class QJsonObject;

class BorderOptions;
class Border;
class Fill;

class Style : public BaseContainer
{
    Q_OBJECT

public:
    explicit Style(QObject *parent = Q_NULLPTR);
    explicit Style(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    QString m_do_objectID;
    QString m_name;
    BorderOptions *m_borderOptions;
    QList<Border*> m_borders;
    QList<Fill*> m_fills;
    double m_endDecorationType;
    double m_miterLimit;
    QString m_sharedObjectID;
    double m_startDecorationType;
};

#endif // STYLE_H
