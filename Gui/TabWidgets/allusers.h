#ifndef ALLUSERS_H
#define ALLUSERS_H

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
#include "Utils/workingistableview.h"

namespace Ui {
class AllUsers;
}

class AllUsers : public QWidget
{
    Q_OBJECT
    Ui::AllUsers *ui;
    QVector<QComboBox*> boxsNameColumn;
    Pagination* pagination;
    WorkingIsTableView* workingIsTableView;
    ModelTypes modelTypes;
    QTimer goToPageTimer;

public:
    explicit AllUsers(QWidget *parent = nullptr);
    ~AllUsers();

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
};

#endif // ALLUSERS_H
