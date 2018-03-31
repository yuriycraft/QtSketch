#ifndef BORDEROPTIONS_H
#define BORDEROPTIONS_H

#include "basecontainer.h"

class QJsonObject;

class BorderOptions : public BaseContainer
{
    Q_OBJECT

public:
    explicit BorderOptions(QObject *parent = Q_NULLPTR);
    explicit BorderOptions(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QList<double> &dashPattern() const;
    bool isEnabled() const;
    double lineCapStyle() const;
    double lineJoinStyle() const;

private:
    QList<double> m_dashPattern;
    bool m_isEnabled;
    double m_lineCapStyle;
    double m_lineJoinStyle;
};

#endif // BORDEROPTIONS_H
