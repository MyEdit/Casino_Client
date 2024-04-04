#ifndef WINDOW_PLAYER_H
#define WINDOW_PLAYER_H

#include "BaseClass/baseclassmainmenu.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Games/Tabel/table.h"

namespace Ui {
class Window_Player;
}

class Window_Player : public BaseClassMainMenu
{
    Q_OBJECT
    Ui::Window_Player *ui;

public:
    explicit Window_Player(QWidget *parent = nullptr);
    ~Window_Player();

    void setTabels();

private:
    void assigningValues() override;
    void completionTabWidget() override;
    void rendering_WelcomeTab() override;
    void uploadingPhotoPlaer();
    void settingUserInformation() override;
    void connects() override;

private slots:
    void on_activeTables_clicked();
    void on_credits_clicked();
    void on_replenish_clicked();
};

#endif // WINDOW_PLAYER_H
