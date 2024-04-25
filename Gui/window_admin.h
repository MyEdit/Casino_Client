#ifndef WINDOW_ADMIN_H
#define WINDOW_ADMIN_H

#include "Gui/TabWidgets/Admin/activetables.h"
#include "Gui/TabWidgets/Admin/users.h"
#include "Gui/TabWidgets/Admin/banlist.h"
#include "Gui/TabWidgets/Admin/stuffusers.h"
#include "Gui/TabWidgets/welcome.h"
#include "Gui/TabWidgets/Admin/credits.h"
#include "Gui/TabWidgets/Admin/payments.h"
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
    QSharedPointer<Welcome> welcomeTab;

public:
    explicit Window_Admin(QWidget *parent = nullptr);
    ~Window_Admin();

    void setModel_UsersTab(QSharedPointer<ModelData> model);
    void setModel_ActiveTablesTab(QSharedPointer<ModelData> model);
    void setModel_BanListTab(QSharedPointer<ModelData> model);
    void setModel_StuffUsersTab(QSharedPointer<ModelData> model);
    void setModel_CreditsTab(QSharedPointer<ModelData> model);
    void setModel_PaymentsTab(QSharedPointer<ModelData> model);

private:
    void assigningValues() override;
    void completionTabWidget() override;
    void rendering_ActiveTablesTab();
    void rendering_UsersTab();
    void rendering_BanListTab();
    void rendering_StuffUsersTab();
    void rendering_CreditsTab();
    void rendering_PaymentsTab();
    void rendering_WelcomeTab() override;
    void uploadingPhotoEmployee();
    void settingUserInformation() override;
    const QString definingrRole();
    void rendoringForTableManager();
    void rendoringForAdmin();
    void rendoringForUser();
    void connects() override;

private slots:
    void on_activeTables_clicked();
    void on_users_clicked();
    void on_stuffUsers_clicked();
    void on_banList_clicked();
    void on_credits_clicked();
    void on_payments_clicked();
};

#endif // WINDOW_ADMIN_H
