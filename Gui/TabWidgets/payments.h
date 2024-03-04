#ifndef PAYMENTS_H
#define PAYMENTS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"

namespace Ui {
class Payments;
}

class Payments : public BaseClassSearchWindow
{
    Ui::Payments *ui;

public:
    explicit Payments(QWidget *parent = nullptr);
    ~Payments();

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

#endif // PAYMENTS_H
