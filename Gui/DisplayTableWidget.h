#ifndef DISPLAYTABLEWIDGET_H
#define DISPLAYTABLEWIDGET_H

#include <QTableWidget>
class DisplayTableWidget :public QTableWidget
{
    Q_OBJECT
public:
    explicit DisplayTableWidget(
            QWidget* parent=nullptr);

    void pushDisplayItemFromFile(const QString&file,const QString&title);
    void clear();
protected slots:
    //void m_slot_clicked_display_widget(int row, int column);
    void m_slot_current_cell_changed(int currentRow, int currentColumn, int previousRow, int previousColumn);
    //void m_slot_item_selection_changed();
private:
    int m_count;
};

#endif // DISPLAYTABLEWIDGET_H
