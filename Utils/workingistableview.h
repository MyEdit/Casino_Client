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

    QTableView* tableView;
    QVector<QComboBox*>* boxsNameColumn;
    QVector<QString> headers;

public:
    WorkingIsTableView(QTableView* table, QVector<QComboBox*>* boxsNameColumn = nullptr);

    void settingVisualTableView();
    void setModel(QSharedPointer<QStandardItemModel> model);
    void setCurrentIndex(QModelIndex index);
    bool checkDataInTable();

private:
    void setValueNameColumn();
    QVector<QString> getColumnHeaders();

signals:
    void unlockInterface(const bool);
};

#endif // WORKINGISTABLEVIEW_H
