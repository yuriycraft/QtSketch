#ifndef ASSETCOLLECTION_H
#define ASSETCOLLECTION_H

#include "basecontainer.h"

class QJsonObject;

class Color;
class ImageCollection;

class AssetCollection : public BaseContainer
{
    Q_OBJECT
    Q_PROPERTY(QList<Color*> colors READ colors CONSTANT)
    Q_PROPERTY(ImageCollection* imageCollection READ imageCollection CONSTANT)

public:
    explicit AssetCollection(QObject *parent = Q_NULLPTR);
    explicit AssetCollection(const QJsonObject &jsonObj, QObject *parent = Q_NULLPTR);

    const QList<Color*> &colors() const;
    ImageCollection *imageCollection() const;

private:
    QList<Color*> m_colors;
    //TODO gradients
    ImageCollection *m_imageCollection;
    //TODO images
};

#endif // ASSETCOLLECTION_H
