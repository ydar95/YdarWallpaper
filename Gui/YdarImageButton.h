#ifndef YDARIMAGEBUTTON_H
#define YDARIMAGEBUTTON_H

#include <QWidget>
#include <QPushButton>
class QMouseEvent;
class QPixmap;
class YdarImageButton : public QPushButton
{
    Q_OBJECT
public:
    /*
    explicit YdarImageButton(
                const QPixmap& default_pix,
                const QPixmap& touch_pix,
                QWidget *parent=nullptr
            );
    */
    explicit YdarImageButton(
                const QString& default_url,
                const QString& hover_url="",
                const QString& pressed_url="",
                QWidget *parent=nullptr
            );
};

#endif // YDARIMAGEBUTTON_H
