#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T00:16:04
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GLSL_Render_BackGround
TEMPLATE = app


SOURCES += main.cpp\
    WallpaperUtils.cpp \
    GLViewWidget.cpp

HEADERS  += \
    WallpaperUtils.h \
    GLViewWidget.h

FORMS    += \
    GLViewWidget.ui

INCLUDEPATH += $$PWD/include

LIBS        += -L$$PWD/lib
LIBS        += -lfreeglut -lglew32 -lglew32s
LIBS        += -luser32

DISTFILES += \
    curve.flag
