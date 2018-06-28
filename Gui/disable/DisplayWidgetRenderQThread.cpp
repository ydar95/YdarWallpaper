#include "DisplayWidgetRenderQThread.h"
#include "DisplayWidget.h"
#include <QCoreApplication>
DisplayWidgetRenderQThread::DisplayWidgetRenderQThread(
        DisplayWidget *widget ,
        QWidget *parent):
    QThread(parent),
    m_widget(widget),
    m_is_quit(false)
{

}

DisplayWidgetRenderQThread::~DisplayWidgetRenderQThread(){
    stop();
}

void DisplayWidgetRenderQThread::run()
{

   m_widget->makeCurrent();
   int i=0;
   while(m_is_quit==false){
       glClear(GL_COLOR_BUFFER_BIT);
       glRectf(-1,1,1,-1);
       float val=(i%256)/256.f;
       glClearColor(val,val,val,1);
       m_widget->swapBuffers();
       i++;
    }
    m_widget->doneCurrent();
    m_widget->context()->moveToThread(QCoreApplication::instance()->thread());
}

void DisplayWidgetRenderQThread::stop(){
    m_is_quit=true;
    quit();
    wait();
}

