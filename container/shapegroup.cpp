#include "shapegroup.h"

#include <QDebug>

ShapeGroup::ShapeGroup(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(jsonObj, parent)
{
}

bool ShapeGroup::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
