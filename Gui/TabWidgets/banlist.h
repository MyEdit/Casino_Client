#ifndef BANLIST_H
#define BANLIST_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/w_ban.h"

namespace Ui {
class BanList;
}

class BanList : public BaseClassSearchWindow
{
    Ui::BanList *ui;
    QSharedPointer<Add_Ban> addBan;

public:
    explicit BanList(QWidget *parent = nullptr);
    ~BanList();

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

#endif // BANLIST_H
