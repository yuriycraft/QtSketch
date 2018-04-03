#include "shapegroup.h"

#include <QDebug>

ShapeGroup::ShapeGroup(QObject *parent) :
    BaseContainer(parent)
{
}

bool ShapeGroup::parseProperty(const QString &key, const QJsonValue &value)
{
    //TODO
    qWarning() << "not implemented";

    return BaseContainer::parseProperty(key, value);
}
