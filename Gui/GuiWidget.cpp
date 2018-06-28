#include "GuiWidget.h"
#include "YdarImageButton.h"
#include <QPixmap>
#include <QLabel>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
GuiWidget::GuiWidget(
        QWidget *parent):
    QWidget(parent),
    m_moveing(false)
{
    m_pix.load(":/Gui/MainWindow.png");
    m_title_defuat_pix.load(":/Gui/Title.png");


    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);
    this->resize(m_pix.size());


    m_title=new QLabel(this);
    m_title->setPixmap(m_title_defuat_pix);
    m_title->setGeometry(3,5,m_title_defuat_pix.width()-5,m_title_defuat_pix.height());

    m_mini_btn=new YdarImageButton(":/Gui/Mini_Btn_Default.png",
                                   ":/Gui/Mini_Btn_Touch.png",
                                   "",this);
    m_mini_btn->setGeometry(850,12,32,32);

    m_close_btn=new YdarImageButton(":/Gui/Close_Btn_Default.png",
                                    ":/Gui/Close_Btn_Touch.png",
                                    "",this);
    m_close_btn->setGeometry(888,12,32,32);

    connect(m_mini_btn, SIGNAL(released()), this, SLOT(m_slots_mini_btn_release()));
    connect(m_close_btn, SIGNAL(released()), this, SLOT(m_slots_close_btn_release()));

}

void GuiWidget::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.drawPixmap(0,0,m_pix);
}

void GuiWidget::m_slots_mini_btn_release(){
    this->showMinimized();
}

void GuiWidget::m_slots_close_btn_release(){
    this->close();
}

void GuiWidget::mouseMoveEvent(QMouseEvent *e){
    const auto enterBtn=[](QPoint pp, QPushButton *btn)->bool
    {
       int height = btn->height();
       int width = btn->width();
       QPoint btnMinPos = btn->pos();
       QPoint btnMaxPos = btn->pos();
       btnMaxPos.setX(btn->pos().x()+width);
       btnMaxPos.setY(btn->pos().y()+height);
       if(pp.x() >= btnMinPos.x() && pp.y() >= btnMinPos.y()
           && pp.x() <= btnMaxPos.x() && pp.y() <= btnMaxPos.y())
           return true;
       else
           return false;
    };

    e->accept();
    if(!(enterBtn(e->pos(),m_mini_btn)||enterBtn(e->pos(),m_close_btn))){
        //通过事件event->globalPos()知道鼠标坐标，鼠标坐标减去鼠标相对于窗口位置，就是窗口在整个屏幕的坐标
        if (m_moveing && (e->buttons() && Qt::LeftButton)
            && (e->globalPos()-m_move_position).manhattanLength() > QApplication::startDragDistance())
        {
            move(e->globalPos()-m_move_position);
            m_move_position = e->globalPos() - pos();
        }
    }
    return QWidget::mousePressEvent(e);
}

void GuiWidget::mousePressEvent(QMouseEvent *e){
    const auto enterLab=[](QPoint pp, QLabel *lab)->bool
    {
       int height = lab->height();
       int width = lab->width();
       QPoint btnMinPos = lab->pos();
       QPoint btnMaxPos = lab->pos();
       btnMaxPos.setX(lab->pos().x()+width);
       btnMaxPos.setY(lab->pos().y()+height);
       if(pp.x() >= btnMinPos.x() && pp.y() >= btnMinPos.y()
           && pp.x() <= btnMaxPos.x() && pp.y() <= btnMaxPos.y())
           return true;
       else
           return false;
    };
    e->accept();
    if(enterLab(e->pos(),m_title)){
        m_move_position = e->globalPos() - pos();
        this->m_moveing=true;
    }
    return QWidget::mousePressEvent(e);
}

void GuiWidget::mouseReleaseEvent(QMouseEvent *e){
    this->m_moveing=false;
    return QWidget::mousePressEvent(e);
}
