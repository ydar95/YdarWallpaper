#include "YdarImageButton.h"
#include <QPixmap>
#include <QSize>
#include <QMouseEvent>

#include<QDebug>
/*
YdarImageButton::YdarImageButton(
        const QPixmap& default_pix,
        const QPixmap& touch_pix,
        QWidget *parent):
    m_default_pix(default_pix),
    m_touch_pix(touch_pix),
    QPushButton(parent)
{
    this->setStyleSheet("border:none");
    this->setIcon(m_default_pix);
    this->setIconSize(m_default_pix.size());
    setMouseTracking(true);
}
*/
YdarImageButton::YdarImageButton(
        const QString& default_url,
        const QString& hover_url,
        const QString& pressed_url,
        QWidget *parent):
    QPushButton(parent)
{
    this->setFixedSize(QPixmap(default_url).size());
    QString sheet="QPushButton"
                  "{"
                  "    border-image:url("+default_url+");"
                  "}";

    if(hover_url!=""){
        sheet+="QPushButton:hover"
                "{"
                "    border-image:url("+hover_url+");"
                "}";
    }

    if(pressed_url!=""){
        sheet+="QPushButton:pressed"
               "{"
               "    border-image:url("+pressed_url+");"
               "}";
    }
    this->setStyleSheet(sheet);
}


