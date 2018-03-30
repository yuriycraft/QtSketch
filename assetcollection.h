#ifndef ASSETCOLLECTION_H
#define ASSETCOLLECTION_H

#include "basecontainer.h"

class QJsonObject;

class ImageCollection;

class AssetCollection : public BaseContainer
{
    Q_OBJECT

public:
    explicit AssetCollection(QObject *parent = Q_NULLPTR);
    explicit AssetCollection(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

private:
    //TODO colors
    //TODO gradients
    ImageCollection *m_imageCollection;
    //TODO images
};

#endif // ASSETCOLLECTION_H