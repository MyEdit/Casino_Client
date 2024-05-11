#ifndef WINDOW_PLAYER_H
#define WINDOW_PLAYER_H

#include "BaseClass/baseclassmainmenu.h"
#include "Network/PacketsActions/p_authorization.h"
#include "Games/Tabel/table.h"
#include "Gui/TabWidgets/Player/gametable.h"
#include "Gui/TabWidgets/Player/playercredits.h"
#include "Gui/TabWidgets/Player/playerpayments.h"
#include <QSharedPointer>

class GameTable;
class PlayerCredits;
class PlayerPayments;

namespace Ui {
class Window_Player;
}

class Window_Player : public BaseClassMainMenu
{
    Q_OBJECT
    Ui::Window_Player *ui;
    QSharedPointer<GameTable> gameTabels;
    QSharedPointer<PlayerCredits> playerCredits;
    QSharedPointer<PlayerPayments> payments;
    QMap<ModelTypes, std::function<void(QSharedPointer<ModelData>)>> setModelFunction;
    QMap<ModelTypes, std::function<void()>> updateTableFunction;


public:
    explicit Window_Player(QWidget *parent = nullptr);
    ~Window_Player();

    void setTabels();
    void setNewBalance(const QString& newBalance);
    void setModel(QSharedPointer<ModelData> set);
    void updateTable(ModelTypes modelType);

private:
    void assigningValues() override;
    void completionTabWidget() override;
    void rendering_WelcomeTab() override;
    void uploadingPhotoPlaer();
    void settingUserInformation() override;
    void connects() override;
    void rendering_GameTablesTab();
    void rendering_PlayerCreditsTab();
    void rendering_PaymentsTab();
    void initSetModelFunction();
    void initUpdateTableFunction();

private slots:
    void on_gameTables_clicked();
    void on_credits_clicked();
    void on_replenish_clicked();
};

#endif // WINDOW_PLAYER_H
