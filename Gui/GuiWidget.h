#ifndef GUIWIDGET_H
#define GUIWIDGET_H

#include <QWidget>


class YdarImageButton;
class QLabel;
class QPixmap;
class QPoint;
class QMouseEvent;

class GuiWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GuiWidget(QWidget *parent = 0);


protected:
    void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
protected slots:
    virtual void m_slots_mini_btn_release();
    virtual void m_slots_close_btn_release();
private:

    YdarImageButton *m_mini_btn;
    YdarImageButton *m_close_btn;
    QLabel      *m_title;

    bool        m_moveing;
    QPoint      m_move_position;

    QPixmap     m_pix;
    QPixmap     m_title_defuat_pix;


};

#endif // GUIWIDGET_H
