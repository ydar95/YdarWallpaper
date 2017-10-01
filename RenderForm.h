#ifndef RENDERFORM_H
#define RENDERFORM_H

#include <QWidget>
#include <memory>
#include <Windows.h>
#include <QMap>
#include <QResizeEvent>
#include <QString>
#include <opengl/glew.h>
#include <iostream>
using namespace std;
namespace Ui {
class RenderForm;
}

class RenderForm : public QWidget
{
    Q_OBJECT
public:
    static std::shared_ptr<RenderForm> InstancePtr;
public:
    explicit RenderForm(QWidget *parent = 0);
    ~RenderForm();
protected:
    void resizeEvent(QResizeEvent * event);

public:
    Ui::RenderForm *ui;

};



#endif // RENDERFORM_H
