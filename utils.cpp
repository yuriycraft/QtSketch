#include "utils.h"

#include <QString>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>

#include "assetcollection.h"
#include "color.h"
#include "document.h"
#include "imagecollection.h"
#include "msimmutableforeignsymbol.h"
#include "msjsonfilereference.h"
#include "sharedstyle.h"
#include "sharedstylecontainer.h"
#include "sharedtextstylecontainer.h"
#include "style.h"
#include "symbolcontainer.h"
#include "symbolmaster.h"

// QString QJsonValue::toString() const { return toString(QStringLiteral()); }

BaseContainer *getContainer(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        throw QStringLiteral("Could not open file %0 because %1").arg(path).arg(file.errorString());

    return getContainer(file.readAll());
}

BaseContainer *getContainer(const QByteArray &content)
{
    QJsonParseError jsonParseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(content, &jsonParseError);
    if(jsonParseError.error != QJsonParseError::NoError)
        throw QStringLiteral("Could not parse json: %0").arg(jsonParseError.errorString());

    return getContainer(jsonDocument);
}

BaseContainer *getContainer(const QJsonDocument &jsonDocument)
{
    if(!jsonDocument.isObject())
        throw QStringLiteral("json document is not an object");

    return getContainer(jsonDocument.object());
}

BaseContainer *getContainer(const QJsonObject &jsonObj)
{
    if(!jsonObj.contains(QStringLiteral("_class")))
        throw QStringLiteral("json does not contain _class");

    auto classValue = jsonObj.value(QStringLiteral("_class"));

    if(!classValue.isString())
        throw QStringLiteral("_class is not a string");

    auto classString = classValue.toString();

    if(classString == QStringLiteral("assetCollection"))
        return new AssetCollection(jsonObj);
    else if(classString == QStringLiteral("color"))
        return new Color(jsonObj);
    else if(classString == QStringLiteral("document"))
        return new Document(jsonObj);
    else if(classString == QStringLiteral("imageCollection"))
        return new ImageCollection(jsonObj);
    else if(classString == QStringLiteral("MSImmutableForeignSymbol"))
        return new MSImmutableForeignSymbol(jsonObj);
    else if(classString == QStringLiteral("MSJSONFileReference"))
        return new MSJSONFileReference(jsonObj);
    else if(classString == QStringLiteral("sharedStyle"))
        return new SharedStyle(jsonObj);
    else if(classString == QStringLiteral("sharedStyleContainer"))
        return new SharedStyleContainer(jsonObj);
    else if(classString == QStringLiteral("sharedTextStyleContainer"))
        return new SharedTextStyleContainer(jsonObj);
    else if(classString == QStringLiteral("style"))
        return new Style(jsonObj);
    else if(classString == QStringLiteral("symbolContainer"))
        return new SymbolContainer(jsonObj);
    else if(classString == QStringLiteral("symbolMaster"))
        return new SymbolMaster(jsonObj);
    else
        throw QStringLiteral("Unknown container type %0").arg(classString);
}
