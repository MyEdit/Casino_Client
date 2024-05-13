#ifndef PLAYERPAYMENTS_H
#define PLAYERPAYMENTS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/Filters/Player/f_playerpayment.h"

namespace Ui {
class PlayerPayments;
}

class PlayerPayments : public BaseClassSearchWindow
{
    Ui::PlayerPayments *ui;

public:
    explicit PlayerPayments(QWidget *parent = nullptr);
    ~PlayerPayments();

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


#endif // PLAYERPAYMENTS_H
