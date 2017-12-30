#ifndef EXAMPLEPAINTSURFACE_H
#define EXAMPLEPAINTSURFACE_H

#include "OpenGlOffscreenSurface.h"

class ExamplePaintSurface
    : public OpenGlOffscreenSurface
{
public:
    explicit ExamplePaintSurface(
            QScreen* targetScreen = nullptr,
            const QSize& size = QSize (1, 1));

    virtual ~ExamplePaintSurface() override;

protected:
    virtual void initializeGL() override;

    virtual void resizeGL(
            int width,
            int height) override;

    virtual void paintGL() override;
};


#endif  // EXAMPLEPAINTSURFACE_H

