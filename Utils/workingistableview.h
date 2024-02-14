#ifndef WORKINGISTABLEVIEW_H
#define WORKINGISTABLEVIEW_H

#include <QTableView>
#include <QComboBox>
#include <QHeaderView>
#include <QStandardItemModel>
#include "Utils/Message.h"

class WorkingIsTableView
{
    QTableView* _tableView;
    QVector<QComboBox*>* _boxsNameColumn;
    QVector<QString> _headers;

public:
    WorkingIsTableView(QTableView* table, QVector<QComboBox*>* boxsNameColumn = nullptr);

    void settingVisualTableView();
    void setModel(QStandardItemModel* model);
    void setValueNameColumn();
    QVector<QString> getColumnHeaders();
};

#endif // WORKINGISTABLEVIEW_H
