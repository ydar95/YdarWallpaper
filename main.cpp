#include "MainWindow.h"
#include <QApplication>
#include "Gui/DisplayTableWidget.h"
#include "Gui/DisplayTableWidgetItemWidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*
    DisplayTableWidget d;
    d.show();
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            d.pushDisplayItemFromFile("glsl/Steam.frag",QString::number(i)+","+QString::number(j));
        }
    */
    return a.exec();
}
