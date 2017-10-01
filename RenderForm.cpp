#include "RenderForm.h"
#include "ui_RenderForm.h"
#include "tool.h"
#include <QResizeEvent>
#include <QDebug>
#include <memory>
#include <textfile.h>
std::shared_ptr<RenderForm> RenderForm::InstancePtr;

RenderForm::RenderForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderForm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Tool);
    SetParent((HWND)this->winId(),winHWND::getWorker());
    showFullScreen();
}

void RenderForm::resizeEvent(QResizeEvent * event){

}

RenderForm::~RenderForm()
{
    delete ui;
}
