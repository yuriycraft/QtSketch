#include "containerfactory.h"

#include <QDebug>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>

#include "container/artboard.h"
#include "container/assetcollection.h"
#include "container/bitmap.h"
#include "container/blur.h"
#include "container/border.h"
#include "container/borderoptions.h"
#include "container/color.h"
#include "container/document.h"
#include "container/exportformat.h"
#include "container/exportoptions.h"
#include "container/fill.h"
#include "container/gradient.h"
#include "container/gradientstop.h"
#include "container/graphicscontextsettings.h"
#include "container/group.h"
#include "container/imagecollection.h"
#include "container/innershadow.h"
#include "container/msimmutableforeignsymbol.h"
#include "container/msjsonfilereference.h"
#include "container/oval.h"
#include "container/page.h"
#include "container/polygon.h"
#include "container/rect.h"
#include "container/rectangle.h"
#include "container/rulerdata.h"
#include "container/shadow.h"
#include "container/shapegroup.h"
#include "container/shapepath.h"
#include "container/sharedstyle.h"
#include "container/sharedstylecontainer.h"
#include "container/sharedtextstylecontainer.h"
#include "container/slice.h"
#include "container/style.h"
#include "container/symbolcontainer.h"
#include "container/symbolinstance.h"
#include "container/symbolmaster.h"
#include "container/text.h"
#include "container/textstyle.h"
#include "container/triangle.h"

QHash<QString, QMetaObject> ContainerFactory::m_metaObjects {
    { QStringLiteral("artboard"), Artboard::staticMetaObject },
    { QStringLiteral("assetCollection"), AssetCollection::staticMetaObject },
    { QStringLiteral("bitmap"), Bitmap::staticMetaObject },
    { QStringLiteral("blur"), Blur::staticMetaObject },
    { QStringLiteral("border"), Border::staticMetaObject },
    { QStringLiteral("borderOptions"), BorderOptions::staticMetaObject },
    { QStringLiteral("color"), Color::staticMetaObject },
    { QStringLiteral("document"), Document::staticMetaObject },
    { QStringLiteral("exportFormat"), ExportFormat::staticMetaObject },
    { QStringLiteral("exportOptions"), ExportOptions::staticMetaObject },
    { QStringLiteral("fill"), Fill::staticMetaObject },
    { QStringLiteral("gradient"), Gradient::staticMetaObject },
    { QStringLiteral("gradientStop"), GradientStop::staticMetaObject },
    { QStringLiteral("graphicsContextSettings"), GraphicsContextSettings::staticMetaObject },
    { QStringLiteral("group"), Group::staticMetaObject },
    { QStringLiteral("imageCollection"), ImageCollection::staticMetaObject },
    { QStringLiteral("innerShadow"), InnerShadow::staticMetaObject },
    { QStringLiteral("MSImmutableForeignSymbol"), MSImmutableForeignSymbol::staticMetaObject },
    { QStringLiteral("MSJSONFileReference"), MSJSONFileReference::staticMetaObject },
    { QStringLiteral("oval"), Oval::staticMetaObject },
    { QStringLiteral("page"), Page::staticMetaObject },
    { QStringLiteral("polygon"), Polygon::staticMetaObject },
    { QStringLiteral("rect"), Rect::staticMetaObject },
    { QStringLiteral("rectangle"), Rectangle::staticMetaObject },
    { QStringLiteral("rulerData"), RulerData::staticMetaObject },
    { QStringLiteral("shadow"), Shadow::staticMetaObject },
    { QStringLiteral("shapeGroup"), ShapeGroup::staticMetaObject },
    { QStringLiteral("shapePath"), ShapePath::staticMetaObject },
    { QStringLiteral("sharedStyle"), SharedStyle::staticMetaObject },
    { QStringLiteral("sharedStyleContainer"), SharedStyleContainer::staticMetaObject },
    { QStringLiteral("sharedTextStyleContainer"), SharedTextStyleContainer::staticMetaObject },
    { QStringLiteral("slice"), Slice::staticMetaObject },
    { QStringLiteral("style"), Style::staticMetaObject },
    { QStringLiteral("symbolContainer"), SymbolContainer::staticMetaObject },
    { QStringLiteral("symbolInstance"), SymbolInstance::staticMetaObject },
    { QStringLiteral("symbolMaster"), SymbolMaster::staticMetaObject },
    { QStringLiteral("text"), Text::staticMetaObject },
    { QStringLiteral("textStyle"), TextStyle::staticMetaObject },
    { QStringLiteral("triangle"), Triangle::staticMetaObject }
};

BaseContainer *ContainerFactory::createContainer(const QString &path, QObject *parent)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        throw QStringLiteral("Could not open file %0 because %1").arg(path).arg(file.errorString());

    return createContainer(file, parent);
}

BaseContainer *ContainerFactory::createContainer(QIODevice &device, QObject *parent)
{
    return createContainer(device.readAll(), parent);
}

BaseContainer *ContainerFactory::createContainer(const QByteArray &content, QObject *parent)
{
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(content, &jsonParseError);
    if(jsonParseError.error != QJsonParseError::NoError)
        throw QStringLiteral("Could not parse json: %0").arg(jsonParseError.errorString());

    return createContainer(jsonDocument, parent);
}

BaseContainer *ContainerFactory::createContainer(const QJsonDocument &jsonDocument, QObject *parent)
{
    if(!jsonDocument.isObject())
        throw QStringLiteral("json document is not an object");

    return createContainer(jsonDocument.object(), parent);
}

BaseContainer *ContainerFactory::createContainer(const QJsonObject &jsonObj, QObject *parent)
{
    if(!jsonObj.contains(QStringLiteral("_class")))
        throw QStringLiteral("json does not contain _class");

    auto classValue = jsonObj.value(QStringLiteral("_class"));

    if(!classValue.isString())
        throw QStringLiteral("_class is not a string");

    auto classString = classValue.toString();

    if(!m_metaObjects.contains(classString))
        throw QStringLiteral("Unknown container type %0").arg(classString);

    auto obj = m_metaObjects.value(classString).newInstance(Q_ARG(QObject *, parent));
    if(!obj)
        throw QStringLiteral("Container class could not be constructed");

    auto container = qobject_cast<BaseContainer*>(obj);
    if(!container)
        throw QStringLiteral("Container object could be casted to BaseContainer");

    container->parseFromJson(jsonObj);

    return container;
}
