#include "GlslPaintSurface.h"

//#include <QGLShaderProgram>
//#include <QGLShader>
#include <QString>
#include <QDebug>
#include <QPainter>
#include <QOpenGLShaderProgram>
#include <QOpenGLShader>
#include <opengl/freeglut.h>
GlslPaintSurface::GlslPaintSurface(
        QScreen*     targetScreen,
        const QSize& size)
    : OpenGlOffscreenSurface(targetScreen, size) {
    m_size=size;
    m_program = new  QOpenGLShaderProgram;

    render();
    grabFramebuffer();
}


GlslPaintSurface::~GlslPaintSurface() {}


void GlslPaintSurface::initializeGL() {
    this->makeCurrent();
    qDebug()<<"GlslPaintSurface::initializeGL"<<m_size;

    glClearColor(0.0,0.0,0.0,1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,"void main(void) {gl_FragColor=vec4(0,1,0, 1.0);}");
    m_program->link();
    m_program->bind();
    resizeGL(m_size.width(),m_size.height());
}


void GlslPaintSurface::resizeGL(int width, int height) {
    this->makeCurrent();
    m_size=QSize(width,height);
    qDebug()<<"GlslPaintSurface::resizeGL"<<m_size;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    m_program->setUniformValue("resolution",m_size);
    m_program->setUniformValue("time",0.5f);
}


void GlslPaintSurface::paintGL()
{
    this->makeCurrent();
    qDebug()<<"GlslPaintSurface::paintGL";
    functions()->glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-1,1,1,-1);
}


//通过文件中   设置新的 Fragment 数据
void GlslPaintSurface::setFragmentByFile(const QString& filename){
    this->makeCurrent();
    qDebug()<<"setFragmentByFile";

    m_program->release();
    m_program->removeAllShaders();
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment,filename);
    m_program->link();
    m_program->bind();
    resizeGL(m_size.width(),m_size.height());
}

//通过QString 设置新的 Fragment 数据
void GlslPaintSurface::setFragmentByCode(const QString& code){
    this->makeCurrent();
    qDebug()<<"setFragmentByCode";

    m_program->release();
    m_program->removeAllShaders();
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,code);
    m_program->link();
    m_program->bind();
    resizeGL(m_size.width(),m_size.height());
}
