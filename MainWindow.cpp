#include "MainWindow.h"
#include <QApplication>
#include "ui_MainWindow.h"
#include <WIndows.h>
#include <Qdebug>
#include <RenderForm.h>
#include <memory>
#include <GLRender.h>
#include <QTimer>
#include "textfile.h"
#include <string>
#include <QStringListModel>
#include <filesystem> // Microsoft-specific implementation header file name
using namespace std::experimental::filesystem::v1;

using namespace std;
std::shared_ptr<MainWindow> MainWindow::InstancePtr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer=new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(timerDone()));

    //update viewlist
    QStringList filenames;

    directory_iterator d_iter(path("E:/GitStorage/GLSL_Render_BackGround/GLSL_Render_BackGround/glsl_code")),d_end;
    while(d_iter!=d_end){
        list_filename.push_back(d_iter->path().string());
        filenames+=d_iter->path().filename().string().c_str();
        d_iter++;
    }
    QStringListModel *model = new QStringListModel(filenames);
    ui->listView->setModel(model);

    rdPtr = new GLRender((HWND)RenderForm::InstancePtr->winId());
}

MainWindow::~MainWindow()
{
    delete rdPtr;
    delete ui;
}

void MainWindow::on_MainWindow_destroyed()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{

    //rdPtr = new GLRender((HWND)RenderForm::InstancePtr->winId());
    //rdPtr->loadGlslCode(textFileRead("d:/basic.frag"));
    //rdPtr->resize(1920,1080);
    //rdPtr->render();
}

void MainWindow::timerDone(){
    static float run_time = clock();
    rdPtr->setUniformTime((clock()-run_time)/1000);
    rdPtr->render();
    //qDebug()<<"timer";
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->start(50);
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    auto s=RenderForm::InstancePtr->size();
    timer->stop();
    rdPtr->loadGlslCode(textFileRead(list_filename[index.row()].c_str()));
    rdPtr->resize(s.width(),s.height());
    timer->start(50);
}
