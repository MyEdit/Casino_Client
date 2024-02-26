#ifndef ALLUSERS_H
#define ALLUSERS_H

#include <QWidget>
#include "QStandardItemModel"
#include "Network/PacketTypes.h"
#include <QMutex>
#include <math.h>
#include <QTimer>
#include <QMessageBox>
#include "Utils/pagination.h"
#include "BaseClass/baseclasssearchwindow.h"

namespace Ui {
class AllUsers;
}

class AllUsers : public BaseClassSearchWindow
{
    Q_OBJECT
    Ui::AllUsers *ui;

public:
    explicit AllUsers(QWidget *parent = nullptr);
    ~AllUsers();

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

#endif // ALLUSERS_H
