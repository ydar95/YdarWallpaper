#include <QApplication>
#include <QImage>
#include <Windows.h>
#include "GLViewWidget.h"

#include "WallpaperUtils.h"
#include"Tool/GlslPaintSurface.h"
#include "GUI/MainWidget.h"

#include <QSize>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    GlslPaintSurface s(nullptr,QSize(300,200));
    //s.render();
    //s.resize(300, 200);
    s.setFragmentByFile("C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");
    s.render();
    s.grabFramebuffer().save("x.png");

    s.setFragmentByFile("E:/GitStorage/GLSL_Render_BackGround/GLSL_Render_BackGround/glsl_code/Dream.frag");
    s.render();
    s.grabFramebuffer().save("y.png");

    GLViewWidget view;
    view.showFullScreen();
    SetParent((HWND)view.winId(),WallpaperUtils::GetWorkerW());
    view.setFragmentByFile("C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");
    */
    MainWidget W;
    W.show();

    return a.exec();
}
