#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QGLWidget>
#include <QGLShaderProgram>
#include <QGLShader>
#include <QString>
#include <QSharedPointer>
#include <QWeakPointer>
#include <QOpenGLFunctions>
#include <QThread>
#include <QDebug>
#include <QTimer>

#include "../Utils/TickCount.h"
class DisplayWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit DisplayWidget(
            QWidget *parent = 0);

    void displayWinWallpaper(); // hide widget
    void setFragmentFromFile(const QString& file);
    void setFragmentFromCode(const QString& code);
    //void displayGlsl();
    QWeakPointer<QGLShaderProgram> getQGLShaderProgram();
    void toWallpaperParent();
signals:
    void finishRender(float dt);
public slots:
    void runGlsl();
    void stopGlsl();
protected  slots:
    void updateVariable(float dt);
    void timerOut();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    QSharedPointer<QGLShaderProgram> m_program;
    QTimer                           m_render_timer;
    float                            m_render_local_time_sec;
    TickCount                        m_tick_count;
};



#endif // DISPLAYWIDGET_H
