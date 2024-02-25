#ifndef EXISTINGTABLES_H
#define EXISTINGTABLES_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"

class Pagination;

namespace Ui {
class ExistingTables;
}

class ExistingTables : public BaseClassSearchWindow
{
    Ui::ExistingTables *ui;
    Pagination* pagination;

public:
    explicit ExistingTables(QWidget *parent = nullptr);
    ~ExistingTables();

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

#endif // EXISTINGTABLES_H
