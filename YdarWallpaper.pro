#-------------------------------------------------
#
# Project created by QtCreator 2018-06-22T00:13:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YdarWallpaper
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Utils/GlslPaintSurface.cpp \
    Utils/OpenGlOffscreenSurface.cpp \
    Utils/WallpaperUtils.cpp \
    Gui/YdarImageButton.cpp \
    Gui/DisplayWidget.cpp \
    Gui/GuiWidget.cpp \
    Utils/TickCount.cpp \
    Gui/DisplayTableWidget.cpp \
    Gui/DisplayTableWidgetItemWidget.cpp

HEADERS  += MainWindow.h \
    Utils/GlslPaintSurface.h \
    Utils/OpenGlOffscreenSurface.h \
    Utils/WallpaperUtils.h \
    Gui/YdarImageButton.h \
    Gui/DisplayWidget.h \
    Gui/GuiWidget.h \
    Utils/TickCount.h \
    Gui/DisplayTableWidget.h \
    Gui/DisplayTableWidgetItemWidget.h

RESOURCES += \
    Resource.qrc
