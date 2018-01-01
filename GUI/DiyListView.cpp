#include "DiyListView.h"

#include <QString>
#include <QImage>
#include <QStandardItemModel>
#include <QIcon>
#include <QPixmap>
#include <QDebug>
DiyListView::DiyListView(QWidget *parent):
    QListView(parent)
{
    this->setViewMode(QListView::IconMode);
    this->setMovement(QListView::Static);
    this->setIconSize(QSize(256,144));
    this->setGridSize(QSize(273,170));
    this->setResizeMode(QListView::Fixed);
    m_viewListDisplay_ItemModel=new QStandardItemModel(this);
    this->setModel(m_viewListDisplay_ItemModel);
}

DiyListView::~DiyListView(){

}

void DiyListView::insert(int index, const QString &title, const QImage &img){
    m_viewListDisplay_ItemModel->insertRow(index,
                    new QStandardItem(QIcon(QPixmap::fromImage(img)),title));
}

void DiyListView::push_back(const QString &title, const QImage &img){
    qDebug()<<img.size();
    m_viewListDisplay_ItemModel->appendRow(new QStandardItem(QIcon(QPixmap::fromImage(img)),title));
}

QStandardItemModel* DiyListView::getModel(){
    return m_viewListDisplay_ItemModel;
}
