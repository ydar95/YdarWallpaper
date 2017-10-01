#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T00:16:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GLSL_Render_BackGround
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    RenderForm.cpp \
    textfile.cpp \
    GLRender.cpp

HEADERS  += MainWindow.h \
    RenderForm.h \
    tool.h \
    textfile.h \
    GLRender.h

FORMS    += MainWindow.ui \
    RenderForm.ui

INCLUDEPATH += $$PWD/include

LIBS        += -L$$PWD/lib
LIBS        += -lfreeglut -lglew32 -lglew32s
LIBS        += -luser32
