#ifndef DIY_QWIDGET_H
#define DIY_QWIDGET_H

#include <QWidget>

class QPixmap;
class QPushButton;
class QLabel;
class QPoint;

class DIY_QWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DIY_QWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);

private slots:
    void m_slots_mini_btn_release();
    void m_slots_close_btn_release();
private:
    QPixmap  m_pix;
    QPushButton *m_mini_btn;
    QPushButton *m_close_btn;
    QLabel      *m_title;

    bool        m_moveing;
    QPoint      m_move_position;
    bool        m_close_btn_status;
    bool        m_mini_btn_status;
private:
    QPixmap m_title_defuat_pix;
    QPixmap m_mini_btn_defuat_pix;
    QPixmap m_close_btn_defuat_pix;
    QPixmap m_mini_btn_touch_pix;
    QPixmap m_close_btn_touch_pix;
};

#endif // DIY_QWIDGET_H
