#ifndef DISPLAYWIDGETRENDERQTHREAD_H
#define DISPLAYWIDGETRENDERQTHREAD_H

#include <QThread>
#include <QWidget>

class DisplayWidget;

class DisplayWidgetRenderQThread : public QThread
{
    Q_OBJECT
public:
    explicit DisplayWidgetRenderQThread(
            DisplayWidget *widget ,
            QWidget *parent=nullptr);

    ~DisplayWidgetRenderQThread();

protected:
    void run() override;
    void stop();
private:
    DisplayWidget*m_widget;
    bool          m_is_quit;
};

#endif // DISPLAYWIDGETRENDERQTHREAD_H
