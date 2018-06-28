#ifndef EXAMPLEPAINTSURFACE_H
#define EXAMPLEPAINTSURFACE_H

#include "OpenGlOffscreenSurface.h"
#include <QOpenGLShaderProgram>

#include <QSize>
#include <QImage>
class GlslPaintSurface
    : public OpenGlOffscreenSurface
{
public:
    explicit GlslPaintSurface(
            const QSize& size = QSize (300, 200),
            QScreen* targetScreen = nullptr
            );

    virtual ~GlslPaintSurface() override;

    QImage getGlslBufferFromFile(const QString& file);
    QImage getGlslBufferFromCode(const QString& code);
    GlslPaintSurface& setSize(const QSize& size);
protected:
    //通过文件中   设置新的 Fragment 数据
    void setFragmentByFile(const QString& filename);

    //通过QString 设置新的 Fragment 数据
    void setFragmentByCode(const QString& code);

    virtual void initializeGL() override;

    virtual void resizeGL(int width,int height) override;

    virtual void paintGL() override;
private:
    QOpenGLShaderProgram    *m_program;
    QSize   m_size;
};


#endif  // EXAMPLEPAINTSURFACE_H

