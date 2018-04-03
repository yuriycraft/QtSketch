#include "textstyle.h"

#include <QDebug>
#include <QJsonValue>

TextStyle::TextStyle(QObject *parent) :
    BaseContainer(parent),
    m_verticalAlignment(0.)
{
}

const QString &TextStyle::do_objectID() const
{
    return m_do_objectID;
}

double TextStyle::verticalAlignment() const
{
    return m_verticalAlignment;
}

bool TextStyle::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("do_objectID"))
    {
        Q_ASSERT(value.isString());
        m_do_objectID = value.toString();
        return true;
    }

    if(key == QStringLiteral("verticalAlignment"))
    {
        Q_ASSERT(value.isDouble());
        m_verticalAlignment = value.toDouble();
        return true;
    }

    if(key == QStringLiteral("encodedAttributes"))
    {
        qWarning() << "encodedAttributes not implemented";
        return true;
    }

    return BaseContainer::parseProperty(key, value);
}
