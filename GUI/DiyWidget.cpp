#include "DiyWidget.h"
#include <QApplication>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QScrollBar>
DiyWidget::DiyWidget(QWidget *parent) :
    QWidget(parent),
    m_moveing(false),
    m_close_btn_status(0),
    m_mini_btn_status(0)
{
    m_pix.load(":/gui/MainWindow.png");
    m_close_btn_defuat_pix.load(":/gui/Close_Btn_Default.png");
    m_title_defuat_pix.load(":/gui/Title.png");
    m_mini_btn_defuat_pix.load(":/gui/Mini_Btn_Default.png");
    m_mini_btn_touch_pix.load(":/gui/Mini_Btn_Touch.png");
    m_close_btn_touch_pix.load(":/gui/Close_Btn_Touch.png");


    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
    this->resize(m_pix.size());


    m_title=new QLabel(this);
    m_title->setPixmap(m_title_defuat_pix);
    m_title->setGeometry(3,10,m_title_defuat_pix.width()-10,m_title_defuat_pix.height());



    m_mini_btn=new QPushButton(this);
    m_mini_btn->setIcon(m_mini_btn_defuat_pix);
    m_mini_btn->setIconSize(m_mini_btn_defuat_pix.size());
    m_mini_btn->setGeometry(850,12,32,32);
    m_mini_btn->setStyleSheet("border:none");



    m_close_btn=new QPushButton(this);
    m_close_btn->setIcon(m_close_btn_defuat_pix);
    m_close_btn->setIconSize(m_close_btn_defuat_pix.size());
    m_close_btn->setGeometry(888,12,32,32);
    m_close_btn->setStyleSheet("border:none");


    this->setMouseTracking(true);
    m_title->setMouseTracking(true);
    m_mini_btn->setMouseTracking(true);
    m_close_btn->setMouseTracking(true);


    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(255,255,255,1));
    setPalette(pal);
    setAutoFillBackground(true);
    connect(m_mini_btn, SIGNAL(released()), this, SLOT(m_slots_mini_btn_release()));
    connect(m_close_btn, SIGNAL(released()), this, SLOT(m_slots_close_btn_release()));
}

void DiyWidget::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.drawPixmap(0,0,m_pix);
}

void DiyWidget::mouseMoveEvent(QMouseEvent *e){
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
    if(enterBtn(e->pos(),m_mini_btn)){
        if(m_mini_btn_status==0){
            m_mini_btn_status=1;
            m_mini_btn->setIcon(m_mini_btn_touch_pix);
            m_mini_btn->setIconSize(m_mini_btn_touch_pix.size());
        }
    }else if(enterBtn(e->pos(),m_close_btn)){
        if(m_close_btn_status==0){
            m_close_btn_status=1;
            m_close_btn->setIcon(m_close_btn_touch_pix);
            m_close_btn->setIconSize(m_close_btn_touch_pix.size());
        }
        //else
    }else{
        if(m_close_btn_status){
            m_close_btn->setIcon(m_close_btn_defuat_pix);
            m_close_btn->setIconSize(m_close_btn_defuat_pix.size());
            m_close_btn_status=0;
        }
        if(m_mini_btn_status){
            m_mini_btn->setIcon(m_mini_btn_defuat_pix);
            m_mini_btn->setIconSize(m_mini_btn_defuat_pix.size());
            m_mini_btn_status=0;
        }

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

void DiyWidget::mousePressEvent(QMouseEvent *e){
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

void DiyWidget::mouseReleaseEvent(QMouseEvent *e){
    this->m_moveing=false;
    return QWidget::mousePressEvent(e);
}


void DiyWidget::m_slots_mini_btn_release(){
    this->showMinimized();
}

void DiyWidget::m_slots_close_btn_release(){
    this->close();
}

