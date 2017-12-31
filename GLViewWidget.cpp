#include "GLViewWidget.h"
//#include "ui_GLViewWidget.h"

#include<QTimer>

#include<ctime>
GLViewWidget::GLViewWidget(QWidget *parent) :
    QGLWidget(parent),
    m_time(clock())//,
    //ui(new Ui::GLViewWidget)
{
    //ui->setupUi(this);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slots_update()));
    timer->start(33);
}

GLViewWidget::~GLViewWidget()
{
    //delete ui;
}

void GLViewWidget::initializeGL(){
    qDebug()<<"initializeGL";

    glClearColor(0.0,0.0,0.0,1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);

    m_program.addShaderFromSourceCode(QGLShader::Fragment,"void main(void) {gl_FragColor=vec4(0,1,0, 1.0);}");
    //m_program.addShaderFromSourceFile(QGLShader::Fragment,"C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");
    m_program.link();
    m_program.bind();  // 使该shader真正启动（绑定到当前的opengl上下文中）

}

void GLViewWidget::resizeGL(int w, int h)
{
    qDebug()<<"resizeGL"<<w<<h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    m_program.setUniformValue("resolution",QSize(w,h));
    m_program.setUniformValue("time",m_time/1000);
}

void GLViewWidget::paintGL()
{
    float timer=((GLfloat)clock()-m_time)/1000;
    qDebug()<<"paintGL"<<timer;
    glClear(GL_COLOR_BUFFER_BIT);
    m_program.setUniformValue("time",timer);
    glRectf(-1,1,1,-1);
}

//通过文件中   设置新的 Fragment 数据
void GLViewWidget::setFragmentByFile(const QString& filename){
    qDebug()<<"setFragmentByFile";

    m_program.release();
    m_program.removeAllShaders();
    m_program.addShaderFromSourceFile(QGLShader::Fragment,filename);
    m_program.link();
    m_program.bind();
    resizeGL(this->width(),this->height()); //
}

//通过QString 设置新的 Fragment 数据
void GLViewWidget::setFragmentByCode(const QString& code){
    qDebug()<<"setFragmentByCode";

    m_program.release();
    m_program.removeAllShaders();
    m_program.addShaderFromSourceCode(QGLShader::Fragment,code);
    m_program.link();
    m_program.bind();  // 使该shader真正启动（绑定到当前的opengl上下文中）
    resizeGL(this->width(),this->height()); //
}

void GLViewWidget::slots_update(){
    updateGL();
}
