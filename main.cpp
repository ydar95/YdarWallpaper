#include <QApplication>
#include <Windows.h>
#include "GLViewWidget.h"

#include "WallpaperUtils.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GLViewWidget view;

    view.show();
    view.updateGL();

    SetParent((HWND)view.winId(),WallpaperUtils::GetWorkerW());
    view.showFullScreen();
    view.setFragmentByFile("C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");
    view.updateGL();


    return a.exec();
}
