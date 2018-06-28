#include "DisplayWidget.h"
#include "../Utils/WallpaperUtils.h"

#include <QThread>
#include <QDebug>



DisplayWidget::DisplayWidget(
        QWidget *parent) :
    QGLWidget(parent),
    m_render_local_time_sec(0.0f)
{
    this->setWindowFlags(Qt::SubWindow);
    connect(&m_render_timer, SIGNAL(timeout()), this, SLOT(timerOut()));
    connect(this, SIGNAL(finishRender(float)), this, SLOT(updateVariable(float)));

}

void DisplayWidget::toWallpaperParent(){
    SetParent((HWND)this->winId(),WallpaperUtils::GetWallpaperParentHWND());
    showFullScreen();
}

void DisplayWidget::runGlsl(){
    if(this->isVisible()==false)
        this->setVisible(true);
    m_render_local_time_sec=0.0f;
    m_tick_count.start();
    m_render_timer.start(1000/30);
}

void DisplayWidget::stopGlsl(){
    m_render_timer.stop();
}

void DisplayWidget::displayWinWallpaper(){
    this->setVisible(false);
}

void DisplayWidget::setFragmentFromCode(const QString &code){
    //qDebug()<<__FUNCDNAME__;
    this->makeCurrent();
    if(m_program!=nullptr){
        m_program->release();
    }
    m_program.reset(new QGLShaderProgram(this->context()));
    m_program->addShaderFromSourceCode(QGLShader::Fragment,code);
    m_program->link();
    m_program->bind();
    resizeGL(this->width(),this->height());
}

void DisplayWidget::setFragmentFromFile(const QString &file){
    //qDebug()<<__FUNCDNAME__;
    this->makeCurrent();
    if(m_program!=nullptr){
        m_program->release();
    }
    m_program.reset(new QGLShaderProgram(this->context()));
    m_program->addShaderFromSourceFile(QGLShader::Fragment,file);
    m_program->link();
    m_program->bind();
    resizeGL(this->width(),this->height());
}

QWeakPointer<QGLShaderProgram> DisplayWidget::getQGLShaderProgram(){
    return QWeakPointer<QGLShaderProgram>(this->m_program);
}

void DisplayWidget::initializeGL(){
    //qDebug()<<__FUNCDNAME__;
    this->makeCurrent();
    glClearColor(0.0,0.0,0.0,1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
}


void DisplayWidget::paintGL(){

    //qDebug()<<__FUNCDNAME__;
    this->makeCurrent();
    if(m_program!=nullptr){
        glClear(GL_COLOR_BUFFER_BIT);
        glRectf(-1,1,1,-1);
    }else{
        glClear(GL_COLOR_BUFFER_BIT);
        QString msg_str=u8"Initial";
        QFont font=QFont("Helvetica",21);
        QFontMetrics fm(font);
        int textWidthInPixels = fm.tightBoundingRect(msg_str).width();
        renderText(0-static_cast<double>(textWidthInPixels)/this->width()/2,0.0,0.0,msg_str);
    }
    //this->doneCurrent();
}

void DisplayWidget::resizeGL(int w, int h){
    //qDebug()<<__FUNCDNAME__;
    this->makeCurrent();
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(m_program!=nullptr){
        m_program->setUniformValue("resolution",QSize(w,h));
    }
}

void DisplayWidget::updateVariable(float dt){

    m_render_local_time_sec+=dt;
    if(m_program!=nullptr)
        m_program->setUniformValue("time",m_render_local_time_sec);
    //qDebug()<<m_render_local_time_sec;
}

void DisplayWidget::timerOut(){
    this->makeCurrent();
    m_tick_count.stop();
    float dt=m_tick_count.getSec();
    m_tick_count.start();
    this->updateGL();
    emit finishRender(dt);
}
