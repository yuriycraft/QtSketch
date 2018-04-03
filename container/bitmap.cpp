#include "bitmap.h"

#include <QJsonValue>
#include <QJsonObject>

#include "containerfactory.h"

#include "msjsonfilereference.h"

Bitmap::Bitmap(QObject *parent) :
    Layer(parent),
    m_image(Q_NULLPTR)
{
}

MSJSONFileReference *Bitmap::image() const
{
    return m_image;
}

bool Bitmap::parseProperty(const QString &key, const QJsonValue &value)
{
    if(key == QStringLiteral("image"))
    {
        Q_ASSERT(value.isObject());
        m_image = ContainerFactory::createContainer<MSJSONFileReference>(value.toObject());
        return true;
    }

    return Layer::parseProperty(key, value);
}
