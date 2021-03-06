INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/basecontainer.h \
    $$PWD/containerfactory.h \
    $$PWD/layer.h \
    $$PWD/container/artboard.h \
    $$PWD/container/assetcollection.h \
    $$PWD/container/bitmap.h \
    $$PWD/container/blur.h \
    $$PWD/container/border.h \
    $$PWD/container/borderoptions.h \
    $$PWD/container/color.h \
    $$PWD/container/document.h \
    $$PWD/container/exportformat.h \
    $$PWD/container/exportoptions.h \
    $$PWD/container/fill.h \
    $$PWD/container/gradient.h \
    $$PWD/container/gradientstop.h \
    $$PWD/container/graphicscontextsettings.h \
    $$PWD/container/group.h \
    $$PWD/container/imagecollection.h \
    $$PWD/container/innershadow.h \
    $$PWD/container/msimmutableforeignsymbol.h \
    $$PWD/container/msjsonfilereference.h \
    $$PWD/container/oval.h \
    $$PWD/container/page.h \
    $$PWD/container/polygon.h \
    $$PWD/container/rect.h \
    $$PWD/container/rectangle.h \
    $$PWD/container/rulerdata.h \
    $$PWD/container/shadow.h \
    $$PWD/container/shapegroup.h \
    $$PWD/container/shapepath.h \
    $$PWD/container/sharedstyle.h \
    $$PWD/container/sharedstylecontainer.h \
    $$PWD/container/sharedtextstylecontainer.h \
    $$PWD/container/slice.h \
    $$PWD/container/style.h \
    $$PWD/container/symbolcontainer.h \
    $$PWD/container/symbolinstance.h \
    $$PWD/container/symbolmaster.h \
    $$PWD/container/text.h \
    $$PWD/container/textstyle.h \
    $$PWD/container/triangle.h \
    $$PWD/sketchfile.h

SOURCES += \
    $$PWD/basecontainer.cpp \
    $$PWD/containerfactory.cpp \
    $$PWD/layer.cpp \
    $$PWD/container/artboard.cpp \
    $$PWD/container/assetcollection.cpp \
    $$PWD/container/bitmap.cpp \
    $$PWD/container/blur.cpp \
    $$PWD/container/border.cpp \
    $$PWD/container/borderoptions.cpp \
    $$PWD/container/color.cpp \
    $$PWD/container/document.cpp \
    $$PWD/container/exportformat.cpp \
    $$PWD/container/exportoptions.cpp \
    $$PWD/container/fill.cpp \
    $$PWD/container/gradient.cpp \
    $$PWD/container/gradientstop.cpp \
    $$PWD/container/graphicscontextsettings.cpp \
    $$PWD/container/group.cpp \
    $$PWD/container/imagecollection.cpp \
    $$PWD/container/innershadow.cpp \
    $$PWD/container/msimmutableforeignsymbol.cpp \
    $$PWD/container/msjsonfilereference.cpp \
    $$PWD/container/oval.cpp \
    $$PWD/container/page.cpp \
    $$PWD/container/polygon.cpp \
    $$PWD/container/rect.cpp \
    $$PWD/container/rectangle.cpp \
    $$PWD/container/rulerdata.cpp \
    $$PWD/container/shadow.cpp \
    $$PWD/container/shapegroup.cpp \
    $$PWD/container/shapepath.cpp \
    $$PWD/container/sharedstyle.cpp \
    $$PWD/container/sharedstylecontainer.cpp \
    $$PWD/container/sharedtextstylecontainer.cpp \
    $$PWD/container/slice.cpp \
    $$PWD/container/style.cpp \
    $$PWD/container/symbolcontainer.cpp \
    $$PWD/container/symbolinstance.cpp \
    $$PWD/container/symbolmaster.cpp \
    $$PWD/container/text.cpp \
    $$PWD/container/textstyle.cpp \
    $$PWD/container/triangle.cpp \
    $$PWD/sketchfile.cpp

include(Quazip/Quazip.pri)
