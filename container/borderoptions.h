#ifndef BORDEROPTIONS_H
#define BORDEROPTIONS_H

#include "basecontainer.h"

class QJsonObject;

class BorderOptions : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(QList<double> dashPattern READ dashPattern CONSTANT)
    Q_PROPERTY(bool isEnabled READ isEnabled CONSTANT)
    Q_PROPERTY(double lineCapStyle READ lineCapStyle CONSTANT)
    Q_PROPERTY(double lineJoinStyle READ lineJoinStyle CONSTANT)

public:
    Q_INVOKABLE explicit BorderOptions(QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    const QList<double> &dashPattern() const;
    bool isEnabled() const;
    double lineCapStyle() const;
    double lineJoinStyle() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    QString m_do_objectID;
    QList<double> m_dashPattern;
    bool m_isEnabled;
    double m_lineCapStyle;
    double m_lineJoinStyle;
};

#endif // BORDEROPTIONS_H
