#ifndef WINDOW_ADMIN_H
#define WINDOW_ADMIN_H

#include <QMainWindow>
#include <QTabBar>
#include <QSharedPointer>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QScreen>
#include <QPainter>
#include <QBitmap>
#include "GUI/TabWidgets/creategametable.h"
#include "GUI/TabWidgets/existingtables.h"
#include "GUI/TabWidgets/allusers.h"
#include "GUI/TabWidgets/welcome.h"
#include "Network/networkclient.h"

class P_Authorization;
class ExistingTables;

namespace Ui {
class Window_Admin;
}

class Window_Admin : public QMainWindow
{
    Q_OBJECT

    Ui::Window_Admin *ui;
    QString inactiveButtonStyleSheet;
    QString activeButtonStyleSheet;
    QVector<QPushButton*> buttonSwitchingTab;
    QMap<QPushButton*, QLabel*> selectedButton;

    QSharedPointer<CreateGameTable> createGameTableTab;
    QSharedPointer<ExistingTables> existingTablesTab;
    QSharedPointer<AllUsers> allUsersTab;
    QSharedPointer<Welcome> welcomeTab;

public:
    explicit Window_Admin(QWidget *parent = nullptr);
    ~Window_Admin();

    void setModel_AllUsersTab(ModelData model);
    void setModel_ExistingTab(ModelData model);

private:
    void onNavigationsButton_clicked();
    void assigningValues();
    void completionTabWidget();
    void rendering_CreateGameTableTab();
    void rendering_ExistingTablesTab();
    void rendering_AllUsersTab();
    void rendering_WelcomeTab();
    void prepareStyleSheets();
    void uploadingPhotoEmployee();
    void settingWindowPosition();
    void showEvent(QShowEvent* event) override;

private slots:
    void on_buttonExit_clicked();
    void on_buttonExistingTables_clicked();
    void on_buttonAllUsers_clicked();
    void on_buttonStaff_clicked();
    void on_buttonBlackList_clicked();
    void on_buttonLoanApplocations_clicked();
};

#endif // WINDOW_ADMIN_H
