#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include"DIY_QWidget.h"


class QListView;
class QPushButton;
class GLViewWidget;

class MainWidget : public DIY_QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

private slots:
    void m_slots_btn_release();

private:
    QListView   *m_display_list_view;
    GLViewWidget *m_gl;
    QPushButton  *m_btn;
};

#endif // MAINWIDGET_H
