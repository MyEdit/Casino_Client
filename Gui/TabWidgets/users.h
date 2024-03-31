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
#include "Gui/WorkingWithRecords/w_user.h"
#include "Gui/WorkingWithRecords/w_ban.h"

class W_User;
class W_Ban;

namespace Ui {
class Users;
}

class Users : public BaseClassSearchWindow
{
    Ui::Users *ui;
    QSharedPointer<W_Ban> addBan;
    QSharedPointer<W_User> addUser;
    QSharedPointer<W_User> updateUser;

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

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
    void openCreateBan();
    void deleting() override;
};

#endif // ALLUSERS_H
