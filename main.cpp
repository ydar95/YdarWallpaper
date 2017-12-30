#include <QApplication>
#include <QImage>
#include <Windows.h>
#include "GLViewWidget.h"
#include "MainWindow.h"
#include "WallpaperUtils.h"
#include"Tool/ExamplePaintSurface.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ExamplePaintSurface s;
    s.resize(300, 200);
    s.render();
    s.grabFramebuffer().save("test.png");
    GLViewWidget view;
    view.showFullScreen();
    SetParent((HWND)view.winId(),WallpaperUtils::GetWorkerW());
    view.setFragmentByFile("C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");

    return a.exec();
}
