#ifndef CREDITS_H
#define CREDITS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"

namespace Ui {
class Credits;
}

class Credits : public BaseClassSearchWindow
{
    Ui::Credits *ui;

public:
    explicit Credits(QWidget *parent = nullptr);
    ~Credits();

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
};

#endif // CREDITS_H
