#ifndef PROFIT_H
#define PROFIT_H

#include <QWidget>
#include "BaseClass/baseclasssearchwindow.h"
#include "Utils/pagination.h"

namespace Ui {
class Profit;
}

class Profit : public BaseClassSearchWindow
{
    Q_OBJECT
    Ui::Profit *ui;

public:
    explicit Profit(QWidget *parent = nullptr);
    ~Profit();

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

#endif // PROFIT_H
