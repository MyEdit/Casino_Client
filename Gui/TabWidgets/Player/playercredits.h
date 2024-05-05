﻿#ifndef PLAYERCREDITS_H
#define PLAYERCREDITS_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"

namespace Ui {
class PlayerCredits;
}

class PlayerCredits : public BaseClassSearchWindow
{
    Ui::PlayerCredits *ui;

public:
    explicit PlayerCredits(QWidget *parent = nullptr);
    ~PlayerCredits();

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
};

#endif // PLAYERCREDITS_H