#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include"DiyWidget.h"

#include"Tool/GlslPaintSurface.h"

#include <QVector>
#include <QString>
#include <QModelIndex>
class QListView;
class QPushButton;
class GLViewWidget;
class DiyListView;


class MainWidget : public DiyWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void display(const QString& dir);
private slots:
    void m_slots_btn_release();
    void on_listview_doubleClicked(const QModelIndex &index);
private:
    DiyListView     *m_display_list_view;
    GLViewWidget    *m_gl;
    GLViewWidget    *m_background_view;
    QPushButton     *m_btn;
    GlslPaintSurface*m_glsl_off_render;
    QVector<QString> m_files_vec;
    int              m_index;
};

#endif // MAINWIDGET_H
