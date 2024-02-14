#ifndef WORKINGISTABLEVIEW_H
#define WORKINGISTABLEVIEW_H

#include <QTableView>
#include <QComboBox>
#include <QHeaderView>
#include <QStandardItemModel>
#include "Utils/Message.h"
#include "Network/PacketTypes.h"

class WorkingIsTableView
{
    QTableView* _tableView;
    QVector<QComboBox*>* _boxsNameColumn;
    QVector<QString> _headers;
    QVector<QSharedPointer<QStandardItemModel>> _models;

public:
    WorkingIsTableView(QTableView* table, QVector<QComboBox*>* boxsNameColumn = nullptr);

    void settingVisualTableView();
    void setModel(QStandardItemModel* model);
    void setValueNameColumn();
    QVector<QString> getColumnHeaders();
    void acceptModel(ModelData structModel);
};

#endif // WORKINGISTABLEVIEW_H
