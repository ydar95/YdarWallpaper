#include "GLViewWidget.h"
#include<QTimer>
#include<ctime>
#include <QDebug>
GLViewWidget::GLViewWidget(QWidget *parent) :
    QGLWidget(parent),
    m_time(clock())
    //m_program(this->context())
{
    this->setWindowFlags(Qt::SubWindow);
    m_program =new QGLShaderProgram(this->context());
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slots_update()));
    qDebug()<<"context"<<this->context();


}

GLViewWidget::~GLViewWidget()
{
    //delete ui;
}

void GLViewWidget::initializeGL(){
this->makeCurrent();
    qDebug()<<"initializeGL";

    glClearColor(0.0,0.0,0.0,1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);

    m_program->addShaderFromSourceCode(QGLShader::Fragment,"void main(void) {gl_FragColor=vec4(1,1,1, 1.0);}");
    //m_program.addShaderFromSourceFile(QGLShader::Fragment,"C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");
    m_program->link();
    m_program->bind();  // 使该shader真正启动（绑定到当前的opengl上下文中）

}

void GLViewWidget::resizeGL(int w, int h)
{
    this->makeCurrent();
    qDebug()<<"resizeGL"<<w<<h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_program->setUniformValue("resolution",QSize(w,h));
    m_program->setUniformValue("time",m_time/1000);
}

void GLViewWidget::paintGL()
{
    this->makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT);
    glRectf(-1,1,1,-1);
}

//通过文件中   设置新的 Fragment 数据
void GLViewWidget::setFragmentByFile(const QString& filename){
    this->makeCurrent();
    qDebug()<<"setFragmentByFile";
    m_program->release();
    delete m_program;
    m_program =new QGLShaderProgram(this->context());
    m_program->addShaderFromSourceFile(QGLShader::Fragment,filename);
    m_program->link();
    m_program->bind();
    resizeGL(this->width(),this->height()); //
}

//通过QString 设置新的 Fragment 数据
void GLViewWidget::setFragmentByCode(const QString& code){
    this->makeCurrent();
    qDebug()<<"setFragmentByCode";

    m_program->release();
    //m_program.removeAllShaders();
    delete m_program;

    m_program =new QGLShaderProgram(this->context());
    m_program->addShaderFromSourceCode(QGLShader::Fragment,code);
    m_program->link();
    m_program->bind();  // 使该shader真正启动（绑定到当前的opengl上下文中）
    resizeGL(this->width(),this->height()); //
}

void GLViewWidget::slots_update(){
    this->makeCurrent();
    float timer=((GLfloat)clock()-m_time)/1000;
    m_program->setUniformValue("time",timer);
    updateGL();
}

void GLViewWidget::start(){
    m_timer->start(33);
}

void GLViewWidget::stop(){
    m_timer->stop();
}
