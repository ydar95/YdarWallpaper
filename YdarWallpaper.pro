#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T00:16:04
#
#-------------------------------------------------

QT       += core gui opengl
#CONFIG   += qscintilla2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YdarWallpaper
TEMPLATE = app


SOURCES += main.cpp\
    WallpaperUtils.cpp \
    GLViewWidget.cpp \
    QsciLexerGlsl.cpp \
    Tool/OpenGlOffscreenSurface.cpp \
    Tool/ExamplePaintSurface.cpp \
    GUI/DIY_QWidget.cpp \
    GUI/MainWidget.cpp

HEADERS  += \
    WallpaperUtils.h \
    GLViewWidget.h \
    QsciLexerGlsl.h \
    Tool/OpenGlOffscreenSurface.h \
    Tool/ExamplePaintSurface.h \
    GUI/DIY_QWidget.h \
    GUI/MainWidget.h

FORMS    += \
    GLViewWidget.ui

INCLUDEPATH += $$PWD/include

LIBS        += -L$$PWD/lib
LIBS        += -lfreeglut -lglew32 -lglew32s
LIBS        += -luser32

DISTFILES += \
    curve.flag

RESOURCES += \
    res.qrc
