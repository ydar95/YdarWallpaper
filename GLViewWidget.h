#ifndef GLVIEWWIDGET_H
#define GLVIEWWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QGLShader>
#include <QString>
#include <QDebug>
#include <opengl/freeglut.h>
//namespace Ui {
//class GLViewWidget;
//}

class GLViewWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLViewWidget(QWidget *parent = 0);
    ~GLViewWidget();

    //通过文件中   设置新的 Fragment 数据
    void setFragmentByFile(const QString& filename);

    //通过QString 设置新的 Fragment 数据
    void setFragmentByCode(const QString& code);
protected:

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    // 着色器程序 shader program;
    QGLShaderProgram m_program;

private slots:
    void slots_update();
private:
    GLfloat m_time;
    //Ui::GLViewWidget *ui;
};

#endif // GLVIEWWIDGET_H
