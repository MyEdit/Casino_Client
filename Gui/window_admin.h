#ifndef WINDOW_ADMIN_H
#define WINDOW_ADMIN_H

#include "Gui/TabWidgets/Admin/activetables.h"
#include "Gui/TabWidgets/Admin/users.h"
#include "Gui/TabWidgets/Admin/banlist.h"
#include "Gui/TabWidgets/Admin/stuffusers.h"
#include "Gui/TabWidgets/welcome.h"
#include "Gui/TabWidgets/Admin/credits.h"
#include "Gui/TabWidgets/Admin/payments.h"
#include "Gui/TabWidgets/Admin/profit.h"
#include "Network/networkclient.h"
#include "Utils/windowtracker.h"
#include "BaseClass/baseclassmainmenu.h"
#include "Network/PacketsActions/p_authorization.h"

class P_Authorization;
class ActiveTables;
class Users;
class StuffUsers;
class BanList;
class Credits;
class Payments;
class Profit;

namespace Ui {
class Window_Admin;
}

class Window_Admin : public BaseClassMainMenu
{
    Ui::Window_Admin *ui;
    Roles role;

    QSharedPointer<ActiveTables> activeTables;
    QSharedPointer<Users> users;
    QSharedPointer<StuffUsers> stuffUsers;
    QSharedPointer<BanList> banList;
    QSharedPointer<Credits> credits;
    QSharedPointer<Payments> payments;
    QSharedPointer<Profit> profit;
    QSharedPointer<Welcome> welcomeTab;
    QMap<ModelTypes, std::function<void(QSharedPointer<ModelData>)>> setModelFunction;
    QMap<ModelTypes, std::function<void()>> updateTableFunction;

public:
    explicit Window_Admin(QWidget *parent = nullptr);
    ~Window_Admin();

    void setModel(QSharedPointer<ModelData> set);
    void updateTable(ModelTypes modelType);

private:
    void assigningValues() override;
    void completionTabWidget() override;
    void rendering_ActiveTablesTab();
    void rendering_UsersTab();
    void rendering_BanListTab();
    void rendering_StuffUsersTab();
    void rendering_CreditsTab();
    void rendering_PaymentsTab();
    void rendering_ProfitTab();
    void rendering_WelcomeTab() override;
    void uploadingPhotoEmployee();
    void settingUserInformation() override;
    void rendoringForTableManager();
    void rendoringForAdmin();
    void connects() override;
    void initSetModelFunction();
    void initUpdateTableFunction();

private slots:
    void on_activeTables_clicked();
    void on_users_clicked();
    void on_stuffUsers_clicked();
    void on_banList_clicked();
    void on_credits_clicked();
    void on_payments_clicked();
    void on_profit_clicked();
};

#endif // WINDOW_ADMIN_H
