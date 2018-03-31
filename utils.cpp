#include "utils.h"

#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>

#include "container/assetcollection.h"
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
#include "container/imagecollection.h"
#include "container/msimmutableforeignsymbol.h"
#include "container/msjsonfilereference.h"
#include "container/page.h"
#include "container/rect.h"
#include "container/rulerdata.h"
#include "container/sharedstyle.h"
#include "container/sharedstylecontainer.h"
#include "container/sharedtextstylecontainer.h"
#include "container/style.h"
#include "container/symbolcontainer.h"
#include "container/symbolmaster.h"
#include "container/textstyle.h"

// QString QJsonValue::toString() const { return toString(QStringLiteral()); }

BaseContainer *createContainer(const QString &path, QObject *parent)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        throw QStringLiteral("Could not open file %0 because %1").arg(path).arg(file.errorString());

    return createContainer(file.readAll(), parent);
}

BaseContainer *createContainer(const QByteArray &content, QObject *parent)
{
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(content, &jsonParseError);
    if(jsonParseError.error != QJsonParseError::NoError)
        throw QStringLiteral("Could not parse json: %0").arg(jsonParseError.errorString());

    return createContainer(jsonDocument, parent);
}

BaseContainer *createContainer(const QJsonDocument &jsonDocument, QObject *parent)
{
    if(!jsonDocument.isObject())
        throw QStringLiteral("json document is not an object");

    return createContainer(jsonDocument.object(), parent);
}

BaseContainer *createContainer(const QJsonObject &jsonObj, QObject *parent)
{
    if(!jsonObj.contains(QStringLiteral("_class")))
        throw QStringLiteral("json does not contain _class");

    auto classValue = jsonObj.value(QStringLiteral("_class"));

    if(!classValue.isString())
        throw QStringLiteral("_class is not a string");

    auto classString = classValue.toString();

    if(classString == QStringLiteral("assetCollection"))
        return new AssetCollection(jsonObj, parent);
    else if(classString == QStringLiteral("blur"))
        return new Blur(jsonObj, parent);
    else if(classString == QStringLiteral("border"))
        return new Border(jsonObj, parent);
    else if(classString == QStringLiteral("borderOptions"))
        return new BorderOptions(jsonObj, parent);
    else if(classString == QStringLiteral("color"))
        return new Color(jsonObj, parent);
    else if(classString == QStringLiteral("document"))
        return new Document(jsonObj, parent);
    else if(classString == QStringLiteral("exportFormat"))
        return new ExportFormat(jsonObj, parent);
    else if(classString == QStringLiteral("exportOptions"))
        return new ExportOptions(jsonObj, parent);
    else if(classString == QStringLiteral("fill"))
        return new Fill(jsonObj, parent);
    else if(classString == QStringLiteral("gradient"))
        return new Gradient(jsonObj, parent);
    else if(classString == QStringLiteral("gradientStop"))
        return new GradientStop(jsonObj, parent);
    else if(classString == QStringLiteral("graphicsContextSettings"))
        return new GraphicsContextSettings(jsonObj, parent);
    else if(classString == QStringLiteral("imageCollection"))
        return new ImageCollection(jsonObj, parent);
    else if(classString == QStringLiteral("MSImmutableForeignSymbol"))
        return new MSImmutableForeignSymbol(jsonObj, parent);
    else if(classString == QStringLiteral("MSJSONFileReference"))
        return new MSJSONFileReference(jsonObj, parent);
    else if(classString == QStringLiteral("page"))
        return new Page(jsonObj, parent);
    else if(classString == QStringLiteral("rect"))
        return new Rect(jsonObj, parent);
    else if(classString == QStringLiteral("rulerData"))
        return new RulerData(jsonObj, parent);
    else if(classString == QStringLiteral("sharedStyle"))
        return new SharedStyle(jsonObj, parent);
    else if(classString == QStringLiteral("sharedStyleContainer"))
        return new SharedStyleContainer(jsonObj, parent);
    else if(classString == QStringLiteral("sharedTextStyleContainer"))
        return new SharedTextStyleContainer(jsonObj, parent);
    else if(classString == QStringLiteral("style"))
        return new Style(jsonObj, parent);
    else if(classString == QStringLiteral("symbolContainer"))
        return new SymbolContainer(jsonObj, parent);
    else if(classString == QStringLiteral("symbolMaster"))
        return new SymbolMaster(jsonObj, parent);
    else if(classString == QStringLiteral("textStyle"))
        return new TextStyle(jsonObj, parent);
    else
        throw QStringLiteral("Unknown container type %0").arg(classString);
}
