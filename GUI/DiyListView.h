#ifndef DIYLISTVIEW_H
#define DIYLISTVIEW_H

#include<QListView>


class QStandardItemModel;
class QImage;
class QString;
class DiyListView :public QListView
{
Q_OBJECT
public:
    explicit DiyListView(QWidget *parent = 0);
    ~DiyListView();
    void insert(int index,const QString &title, const QImage &img);

    void push_back(const QString &title, const QImage &img);

    QStandardItemModel* getModel();
private:
    QStandardItemModel* m_viewListDisplay_ItemModel;
};

#endif // DIYLISTVIEW_H
