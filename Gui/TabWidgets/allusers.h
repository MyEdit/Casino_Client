#ifndef ALLUSERS_H
#define ALLUSERS_H

#include <QWidget>
#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <QMutex>
#include <math.h>
#include <QTimer>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "Utils/workingistableview.h"
#include "BaseClass/baseclasssearchwindow.h"

class Pagination;

namespace Ui {
class AllUsers;
}

class AllUsers : public BaseClassSearchWindow
{
    Q_OBJECT
    Ui::AllUsers *ui;
    Pagination* pagination;

public:
    explicit AllUsers(QWidget *parent = nullptr);
    ~AllUsers();

    void setModel(ModelData model);

private:
    void setValueToMaxPage(int maxPage);
    void assigningValues();
    void updateCurrentPageInLabel(int currentPage);
    void creatingObjects();
    void goToPage();
    void connects();
    void search();
    void selectTypeSearch(int arg);
    void sort();
    void sorting(int arg);
    void onHeaderClicked(int logicalIndex);
};

#endif // ALLUSERS_H
