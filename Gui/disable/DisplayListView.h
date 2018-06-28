#ifndef DISPLAYTABEVIEW_H
#define DISPLAYTABEVIEW_H

#include <QWidget>
#include <QListWidget>

class QStandardItemModel;
class DisplayListView
        : public QListWidget
{
    Q_OBJECT
public:
    explicit DisplayListView(
            QWidget *parent = 0);

private:
    QStandardItemModel* m_view_model;
};

#endif // DISPLAYTABEVIEW_H
