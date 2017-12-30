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
    MainWindow.cpp \
    QsciLexerGlsl.cpp \
    Tool/OpenGlOffscreenSurface.cpp \
    Tool/ExamplePaintSurface.cpp

HEADERS  += \
    WallpaperUtils.h \
    GLViewWidget.h \
    MainWindow.h \
    QsciLexerGlsl.h \
    Tool/OpenGlOffscreenSurface.h \
    Tool/ExamplePaintSurface.h

FORMS    += \
    GLViewWidget.ui \
    MainWindow.ui

INCLUDEPATH += $$PWD/include

LIBS        += -L$$PWD/lib
LIBS        += -lfreeglut -lglew32 -lglew32s
LIBS        += -luser32

DISTFILES += \
    curve.flag
