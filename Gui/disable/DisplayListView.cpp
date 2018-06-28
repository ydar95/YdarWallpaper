#include "DisplayListView.h"
#include "DisplayTableWidgetItemWidget.h"

#include <QListWidgetItem>
DisplayListView::DisplayListView(
        QWidget *parent)
    : QListWidget(parent)
{
    this->setViewMode(QListView::IconMode);
    this->setMovement(QListView::Static);
    //this->setIconSize(QSize(256,144));
    this->setGridSize(QSize(273,170));
    this->setResizeMode(QListView::Fixed);
    QListWidgetItem *item = new QListWidgetItem;
    item->setText("xxx");
    this->addItem(item);
    this->setItemWidget(item,new DisplayTableWidgetItemWidget(this));
}
