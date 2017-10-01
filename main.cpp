#include "MainWindow.h"
#include "RenderForm.h"
#include <QApplication>
#include <opengl/glut.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    RenderForm::InstancePtr.reset(new RenderForm);
    RenderForm::InstancePtr->show();

    MainWindow::InstancePtr.reset(new MainWindow);
    MainWindow::InstancePtr->show();


    return a.exec();
}
