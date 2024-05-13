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
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/Admin/w_user.h"
#include "Gui/WorkingWithRecords/Admin/w_ban.h"
#include "Gui/Filters/Admin/f_user.h"

class W_User;
class W_Ban;

namespace Ui {
class Users;
}

class Users : public BaseClassSearchWindow
{
    Ui::Users *ui;
    QSharedPointer<W_Ban> addBan;
    QSharedPointer<W_User> workingWithUser;

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

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
    void openCreateBan();
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

#endif // ALLUSERS_H
