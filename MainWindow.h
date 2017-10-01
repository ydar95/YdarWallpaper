#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <GLRender.h>
#include <QTimer>
#include <ctime>
#include <string>
#include <QVector>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static std::shared_ptr<MainWindow> InstancePtr;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_MainWindow_destroyed();

    void on_pushButton_clicked();

    void timerDone();

    void on_pushButton_2_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    GLRender *rdPtr;
    QTimer    *timer;
    QVector<string> list_filename;
};

#endif // MAINWINDOW_H
