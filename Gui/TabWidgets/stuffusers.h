#ifndef STUFFUSERS_H
#define STUFFUSERS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/w_stuffuser.h"

class W_StuffUser;

namespace Ui {
class StuffUsers;
}

class StuffUsers : public BaseClassSearchWindow
{
    Ui::StuffUsers *ui;
    QSharedPointer<W_StuffUser> addStuffUser;
    QSharedPointer<W_StuffUser> updateStuffUser;

public:
    explicit StuffUsers(QWidget *parent = nullptr);
    ~StuffUsers();

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
    void deleting() override;
};

#endif // STUFFUSERS_H
