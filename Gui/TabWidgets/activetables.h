#ifndef EXISTINGTABLES_H
#define EXISTINGTABLES_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/Add/add_table.h"
#include "Gui/WorkingWithRecords/Edit/edit_table.h"

namespace Ui {
class ActiveTables;
}

class ActiveTables : public BaseClassSearchWindow
{
    Ui::ActiveTables *ui;
    QSharedPointer<Add_Table> createTable;
    QSharedPointer<Edit_Table> editTable;

public:
    explicit ActiveTables(QWidget *parent = nullptr);
    ~ActiveTables();

private:
    void prepReloadModels() override;
    void setValueToMaxPage(int maxPage) override;
    void assigningValues() override;
    void updateCurrentPageInLabel(int currentPage) override;
    void creatingObjects() override;
    void goToPage() override;
    void connects() override;
    void search() override;
    void onHeaderClicked(int logicalIndex) override;
    void openCreatRecotd() override;
    void openEditRecotd() override;
};

#endif // EXISTINGTABLES_H
