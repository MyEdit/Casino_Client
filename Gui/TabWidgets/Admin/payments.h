#ifndef PAYMENTS_H
#define PAYMENTS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"
#include "Gui/Filters/Admin/f_payment.h"

namespace Ui {
class Payments;
}

class Payments : public BaseClassSearchWindow
{
    Ui::Payments *ui;
    QSharedPointer<F_Payment> filter;

public:
    explicit Payments(QWidget *parent = nullptr);
    ~Payments();

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
    void visibleSort(bool flag) override;
    void visibleSearch(bool flag) override;
    void visibleEditing(bool flag) override;
    void visibleFiltr(bool flag) override;
    void addFilter() override;
    void clearFilter() override;
};

#endif // PAYMENTS_H
