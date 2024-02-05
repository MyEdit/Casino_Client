#ifndef WINDOW_ADMIN_H
#define WINDOW_ADMIN_H

#include <QMainWindow>
#include <QTabBar>
#include <QSharedPointer>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <GUI/TabWidgets/creategametable.h>
#include <GUI/TabWidgets/existingtables.h>
#include <GUI/TabWidgets/allusers.h>

namespace Ui {
class Window_Admin;
}

class Window_Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window_Admin(QWidget *parent = nullptr);
    ~Window_Admin();

private:
    Ui::Window_Admin *ui;
    QString inactiveButtonStyleSheet;
    QString activeButtonStyleSheet;
    QVector<QPushButton*> buttonSwitchingTab;
    QSharedPointer<CreateGameTable> createGameTableTab;
    QSharedPointer<ExistingTables> existingTablesTab;
    QSharedPointer<AllUsers> allUsersTab;
    QMap<QPushButton*, QLabel*> selectedButton;

    void onNavigationsButton_clicked();
    void assigningValues();
    void completionTabWidget();
    void rendering_CreateGameTableTab();
    void rendering_ExistingTablesTab();
    void rendering_AllUsersTab();
    void prepareStyleSheets();

private slots:
    void on_buttonExit_clicked();
    void on_buttonCreateTable_clicked();
    void on_buttonExistingTables_clicked();
    void on_buttonAllUsers_clicked();
};

#endif // WINDOW_ADMIN_H
