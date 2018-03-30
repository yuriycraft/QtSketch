#include "sharedstyle.h"

SharedStyle::SharedStyle(QObject *parent) :
    BaseContainer(parent)
{
}

SharedStyle::SharedStyle(const QJsonObject &jsonObj, QObject *parent) :
    BaseContainer(parent)
{

}
