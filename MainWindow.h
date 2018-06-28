#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "Gui/DisplayWidget.h"
#include "Gui/GuiWidget.h"
#include "Gui/DisplayTableWidget.h"
class MainWindow : public GuiWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateDisplayWidget(const QString&dir_file);

public slots:
    void slot_cell_double_clicked(int row, int column);

public:
    DisplayWidget display;
    DisplayTableWidget *mp_display_table_widget;
    QVector<QString>    m_file_vec;
};

#endif // MAINWINDOW_H
