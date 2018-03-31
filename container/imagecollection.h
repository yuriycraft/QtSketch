#ifndef IMAGECOLLECTION_H
#define IMAGECOLLECTION_H

#include "basecontainer.h"

class QJsonObject;

class ImageCollection : public BaseContainer
{
    Q_OBJECT

public:
    explicit ImageCollection(QObject *parent = Q_NULLPTR);
    explicit ImageCollection(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    //TODO images

private:
    //TODO images
};

#endif // IMAGECOLLECTION_H
