#ifndef DISPLAYTABLEWIDGETITEMWIDGET_H
#define DISPLAYTABLEWIDGETITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include "DisplayWidget.h"

class DisplayTableWidgetItemWidget :
        public QWidget
{
public:
    explicit DisplayTableWidgetItemWidget(
            QWidget *parent=nullptr);

    DisplayWidget& getDisplayWidget();
    void           setTitle(const QString& title);

protected:
    void resizeEvent(QResizeEvent * event) override;
private:
    QLabel          *m_title_label_ptr;
    DisplayWidget   *m_display_widget_ptr;
};

#endif // DISPLAYTABLEWIDGETITEMWIDGET_H
