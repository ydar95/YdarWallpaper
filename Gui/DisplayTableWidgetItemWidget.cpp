#include "DisplayTableWidgetItemWidget.h"
DisplayTableWidgetItemWidget::DisplayTableWidgetItemWidget(
        QWidget *parent):
    QWidget(parent)
{
    m_display_widget_ptr=new DisplayWidget(this);
    m_display_widget_ptr->setGeometry(0,0,256,144);
    m_title_label_ptr =new QLabel(this);
    m_title_label_ptr->setGeometry(0,144,256,15);
    m_title_label_ptr->setAttribute(Qt::WA_TranslucentBackground);
    m_title_label_ptr->setAlignment(Qt::AlignCenter);
    m_title_label_ptr->setFont(QFont("Times", 13, QFont::Bold));
    m_title_label_ptr->setText("Ok");
}

DisplayWidget& DisplayTableWidgetItemWidget::getDisplayWidget()
{
    return *m_display_widget_ptr;
}

void DisplayTableWidgetItemWidget::setTitle(const QString &title){
    m_title_label_ptr->setText(title);
}

void DisplayTableWidgetItemWidget::resizeEvent(QResizeEvent *event){
    int x=(this->width()-256)/2;
    int y=10;//(this->height()-144-21)/2;
    m_display_widget_ptr->move(x,y);
    m_title_label_ptr->setGeometry(0,y+144,this->width(),15);
}
