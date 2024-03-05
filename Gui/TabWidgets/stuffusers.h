#ifndef STUFFUSERS_H
#define STUFFUSERS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/Add/add_stuffuser.h"

class Add_StuffUser;

namespace Ui {
class StuffUsers;
}

class StuffUsers : public BaseClassSearchWindow
{
    Ui::StuffUsers *ui;
    QSharedPointer<Add_StuffUser> addStuffUser;

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
};

#endif // STUFFUSERS_H
