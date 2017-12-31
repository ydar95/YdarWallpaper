#include "MainWidget.h"


#include <QListView>
#include <QLabel>
#include <QPushButton>
#include "GLViewWidget.h"
MainWidget::MainWidget(QWidget *parent) :
    DIY_QWidget(parent)
{
    m_display_list_view=new QListView(this);
    m_display_list_view->setGeometry(10,55,690,515);

    QLabel *versions_label=new QLabel(this);
    versions_label->setText(u8"Version :0.1 By ydar95");
    versions_label->setGeometry(800,575,140,12);

    m_gl=new GLViewWidget(this);
    m_gl->setGeometry(715,90,200,120);


    m_btn=new QPushButton(this);
    m_btn->setGeometry(100,100,100,100);


    connect(m_btn, SIGNAL(released()), this, SLOT(m_slots_btn_release()));
}

void MainWidget::m_slots_btn_release(){
    m_gl->setFragmentByFile("C:/Users/yd/Documents/qt/QT_GLSL_TEST/fsrc.frag");
}
