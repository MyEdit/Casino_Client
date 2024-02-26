#ifndef EXISTINGTABLES_H
#define EXISTINGTABLES_H

#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <math.h>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"

namespace Ui {
class ExistingTables;
}

class ExistingTables : public BaseClassSearchWindow
{
    Ui::ExistingTables *ui;

public:
    explicit ExistingTables(QWidget *parent = nullptr);
    ~ExistingTables();

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
};

#endif // EXISTINGTABLES_H
