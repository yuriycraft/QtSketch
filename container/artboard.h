#pragma once

#include "group.h"

class Color;

class Artboard : public Group
{
    Q_OBJECT

public:
    Q_INVOKABLE explicit Artboard(QObject *parent = Q_NULLPTR);

    Color *backgroundColor() const;
    bool hasBackgroundColor() const;

protected:
    // BaseContainer interface
    virtual bool parseProperty(const QString &key, const QJsonValue &value) Q_DECL_OVERRIDE;

private:
    Color *m_backgroundColor;
    bool m_hasBackgroundColor;
};
