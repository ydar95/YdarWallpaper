#include "DisplayTableWidget.h"

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QHeaderView>
#include "Gui/DisplayWidget.h"
#include "DisplayTableWidgetItemWidget.h"

#include <QDebug>
DisplayTableWidget::DisplayTableWidget(
        QWidget* parent):
    QTableWidget(parent),
    m_count(0)
{
    setColumnCount(3);
    setRowCount(0);

    setShowGrid(false);                   //隐藏网格线
    verticalHeader()->setVisible(false);  //隐藏垂直列表头
    horizontalHeader()->setVisible(false);//隐藏水平列表头
    verticalHeader()->setDefaultSectionSize(170);  //nRowHeight
    horizontalHeader()->setDefaultSectionSize(270);//nColumnWidth
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    setSelectionBehavior(QAbstractItemView::SelectItems);

    connect(this,SIGNAL(currentCellChanged(int,int,int,int)),
            this,SLOT(m_slot_current_cell_changed(int,int,int,int)));

}

void DisplayTableWidget::pushDisplayItemFromFile(const QString &file,const QString&title){
    int x= m_count%this->columnCount();     //行
    int y= m_count/this->columnCount();     //列

    if(y>=this->rowCount())
        this->insertRow(rowCount());
    DisplayTableWidgetItemWidget *pWidget =new DisplayTableWidgetItemWidget(this);
    this->setCellWidget(y, x, pWidget);
    pWidget->getDisplayWidget().setFragmentFromFile(file);
    pWidget->getDisplayWidget().updateGL();
    pWidget->setTitle(title);
    m_count++;
}

void DisplayTableWidget::m_slot_current_cell_changed(
        int currentRow,
        int currentColumn,
        int previousRow,
        int previousColumn)
{

    //qDebug()<<"m_slot_clicked_display_widget"<<currentRow<<currentColumn<<previousRow<<previousColumn;
    if(previousRow!=-1){
        auto ptr=cellWidget(previousRow,previousColumn);
        if(ptr!=nullptr)
        dynamic_cast<DisplayTableWidgetItemWidget*>(ptr)->
                getDisplayWidget().stopGlsl();
    }

    if(currentRow!=-1){
        auto ptr=cellWidget(currentRow,currentColumn);
        if(ptr!=nullptr)
            dynamic_cast<DisplayTableWidgetItemWidget*>(ptr)->
                getDisplayWidget().runGlsl();
    }
}

void DisplayTableWidget::clear(){
    this->setRowCount(0);
    this->clearContents();
    this->m_count=0;
}
