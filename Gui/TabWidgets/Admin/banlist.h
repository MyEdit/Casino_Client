#ifndef BANLIST_H
#define BANLIST_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/WorkingWithRecords/Admin/w_ban.h"

class W_Ban;

namespace Ui {
class BanList;
}

class BanList : public BaseClassSearchWindow
{
    Ui::BanList *ui;
    QSharedPointer<W_Ban> updateBan;

public:
    explicit BanList(QWidget *parent = nullptr);
    ~BanList();

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
    void openEditRecotd() override;
    void deleting() override;
    void openCreatRecotd() override;
    void clearSearchText() override;
    void visibleSort(bool flag) override;
    void visibleSearch(bool flag) override;
    void visibleEditing(bool flag) override;
    void visibleFiltr(bool flag) override;
    void addFilter() override;
    void clearFilter() override;
};

#endif // BANLIST_H
