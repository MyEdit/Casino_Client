#ifndef WORKINGISTABLEVIEW_H
#define WORKINGISTABLEVIEW_H

#include <QTableView>
#include <QComboBox>
#include <QWidget>
#include <QHeaderView>
#include <QStandardItemModel>
#include "Utils/Message.h"
#include "Network/PacketTypes.h"

class WorkingIsTableView : public QWidget
{
    Q_OBJECT

    QTableView* _tableView;
    QVector<QComboBox*>* _boxsNameColumn;
    QVector<QString> _headers;

public:
    WorkingIsTableView(QTableView* table, QVector<QComboBox*>* boxsNameColumn = nullptr);

    void settingVisualTableView();
    void setModel(QStandardItemModel* model);

private:
    void setValueNameColumn();
    QVector<QString> getColumnHeaders();

signals:
    void unlockInterface(bool);
};

#endif // WORKINGISTABLEVIEW_H
