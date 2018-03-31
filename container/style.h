#ifndef STYLE_H
#define STYLE_H

#include "basecontainer.h"

class QJsonObject;

class Blur;
class BorderOptions;
class Border;
class Fill;
class GraphicsContextSettings;
class TextStyle;

class Style : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QString do_objectID READ do_objectID CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(Blur* blur READ blur CONSTANT)
    Q_PROPERTY(BorderOptions* borderOptions READ borderOptions CONSTANT)
    Q_PROPERTY(QList<Border*> borders READ borders CONSTANT)
    Q_PROPERTY(QList<Fill*> fills READ fills CONSTANT)
    Q_PROPERTY(GraphicsContextSettings* contextSettings READ contextSettings CONSTANT)
    Q_PROPERTY(double endDecorationType READ endDecorationType CONSTANT)
    Q_PROPERTY(double miterLimit READ miterLimit CONSTANT)
    Q_PROPERTY(QString sharedObjectID READ sharedObjectID CONSTANT)
    Q_PROPERTY(double startDecorationType READ startDecorationType CONSTANT)
    Q_PROPERTY(TextStyle* textStyle READ textStyle CONSTANT)

public:
    explicit Style(QObject *parent = Q_NULLPTR);
    explicit Style(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QString &do_objectID() const;
    const QString &name() const;
    Blur *blur() const;
    BorderOptions *borderOptions() const;
    const QList<Border*> &borders() const;
    const QList<Fill*> &fills() const;
    GraphicsContextSettings *contextSettings() const;
    double endDecorationType() const;
    double miterLimit() const;
    const QString &sharedObjectID() const;
    double startDecorationType() const;
    TextStyle *textStyle() const;

private:
    QString m_do_objectID;
    QString m_name;
    Blur *m_blur;
    BorderOptions *m_borderOptions;
    QList<Border*> m_borders;
    QList<Fill*> m_fills;
    GraphicsContextSettings *m_contextSettings;
    double m_endDecorationType;
    double m_miterLimit;
    QString m_sharedObjectID;
    double m_startDecorationType;
    TextStyle *m_textStyle;
};

#endif // STYLE_H
