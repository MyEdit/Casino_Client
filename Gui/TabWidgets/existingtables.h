#ifndef EXISTINGTABLES_H
#define EXISTINGTABLES_H

#include <QWidget>
#include "QStandardItemModel"
#include "Utils/Message.h"
#include "Network/PacketTypes.h"
#include "Network/networkclient.h"
#include <QMutex>
#include <math.h>
#include <QTimer>
#include <QMessageBox>
#include "Utils/pagination.h"

class Pagination;

namespace Ui {
class ExistingTables;
}

class ExistingTables : public QWidget
{
    Q_OBJECT
    Ui::ExistingTables *ui;
    QVector<QComboBox*> boxsNameColumn;
    Pagination* pagination;
    WorkingIsTableView* workingIsTableView;
    ModelTypes modelTypes;
    QTimer goToPageTimer;
    QString typeSearch;

public:
    explicit ExistingTables(QWidget *parent = nullptr);
    ~ExistingTables();

    void setModel(ModelData model);

private:
    void workingWithTableView();
    void setValueToMaxPage(int maxPage);
    void assigningValues();
    void updateCurrentPageInLabel(int currentPage);
    void creatingObjects();
    void goToPage();
    void connects();
    void blockingInterface(bool flag);
    void search();
    void blockAndOperate(QObject* widget, const std::function<void()>& operation);
    void selectTypeSearch(int arg);
};

#endif // EXISTINGTABLES_H
