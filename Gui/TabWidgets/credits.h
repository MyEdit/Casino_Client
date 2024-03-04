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

#endif // CREDITS_H
