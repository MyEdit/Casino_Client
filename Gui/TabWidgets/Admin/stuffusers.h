#ifndef STUFFUSERS_H
#define STUFFUSERS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/Admin/w_stuffuser.h"
#include "Gui/Filters/Admin/f_stuffuser.h"

class W_StuffUser;

namespace Ui {
class StuffUsers;
}

class StuffUsers : public BaseClassSearchWindow
{
    Ui::StuffUsers *ui;
    QSharedPointer<W_StuffUser> workingWithStuffUsers;

public:
    explicit StuffUsers(QWidget *parent = nullptr);
    ~StuffUsers();

private:
    void prepReloadModels() override;
    void setValueToMaxPage(const int maxPage) override;
    void assigningValues() override;
    void updateCurrentPageInLabel(const int currentPage) override;
    void creatingObjects() override;
    void goToPage() override;
    void connects() override;
    void search() override;
    void onHeaderClicked(const int logicalIndex) override;
    void openCreatRecotd() override;
    void openEditRecotd() override;
    void deleting() override;
    void clearSearchText() override;
    void visibleSort(const bool flag) override;
    void visibleSearch(const bool flag) override;
    void visibleEditing(const bool flag) override;
    void visibleFiltr(const bool flag) override;
    void addFilter() override;
    void runSearch() override;
    void runGoToPage() override;
};

#endif // STUFFUSERS_H
