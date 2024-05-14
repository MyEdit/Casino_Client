#include "window_player.h"
#include "ui_window_player.h"
#include "Gui/window_auth.h"

Window_Player::Window_Player(QWidget *parent) : BaseClassMainMenu(parent), ui(new Ui::Window_Player)
{
    ui->setupUi(this);
    fullName = P_Authorization::getActualUser()->getName();

    prepareStyleSheets();
    assigningValues();
    completionTabWidget();
    settingUserInformation();
    settingWindowPosition();
    connects();
    settingVisual();

    ui->tabWidget->setCurrentWidget(welcomeTab.get());
}

Window_Player::~Window_Player()
{
    delete ui;
}

void Window_Player::assigningValues()
{
    buttonSwitchingTab.push_back(ui->gameTables);
    buttonSwitchingTab.push_back(ui->replenish);
    buttonSwitchingTab.push_back(ui->credits);

    selectedButton =
    {
        {ui->gameTables, ui->label},
        {ui->replenish, ui->label_2},
        {ui->credits, ui->label_3}
    };
}

void Window_Player::completionTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    rendering_WelcomeTab();
    rendering_GameTablesTab();
    rendering_PlayerCreditsTab();
    rendering_PaymentsTab();
}

void Window_Player::rendering_WelcomeTab()
{
    welcomeTab = QSharedPointer<Welcome>::create(fullName);
    ui->tabWidget->addTab(welcomeTab.data(), "");
}

void Window_Player::uploadingPhotoPlaer()
{
    QSharedPointer<QPixmap> photo = uploadingUserPhoto(P_Authorization::getPlayer()->getPhoto());

    ui->photo->setScaledContents(true);

    if(photo)
        ui->photo->setPixmap(*photo);
    else
        ui->photo->hide();
}

void Window_Player::settingUserInformation()
{
    ui->fullNamePlayer->setText(fullName);
    ui->balance->setText(QString::number(P_Authorization::getPlayer()->getBalance()));
    uploadingPhotoPlaer();
}

void Window_Player::connects()
{
    connect(ui->gameTables, &QPushButton::clicked, this, &Window_Player::on_gameTables_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &Window_Player::on_buttonExit_clicked);
    connect(ui->credits, &QPushButton::clicked, this, &Window_Player::on_credits_clicked);
    connect(ui->replenish, &QPushButton::clicked, this, &Window_Player::on_replenish_clicked);
    connect(ui->buttonChangeUser, &QPushButton::clicked, this, &Window_Player::changeUser);
}

void Window_Player::on_gameTables_clicked()
{
    ui->tabWidget->setCurrentWidget(gameTabelsLoading.get());
    onNavigationsButton_clicked();
}

void Window_Player::on_credits_clicked()
{
    ui->tabWidget->setCurrentWidget(playerCredits.get());
    onNavigationsButton_clicked();
}

void Window_Player::on_replenish_clicked()
{
    ui->tabWidget->setCurrentWidget(payments.get());
    onNavigationsButton_clicked();
}

void Window_Player::setTabels()
{
    gameTabelsLoading->updateTables();
}

void Window_Player::setNewBalance(const QString& newBalance)
{
    ui->balance->setText(newBalance);
}

void Window_Player::setModel(QSharedPointer<ModelData> set)
{
    if (setModelFunction.size() == 0)
        initSetModelFunction();

    setModelFunction[set->modelTypes](set);
}

void Window_Player::updateTable(ModelTypes modelType)
{
    if (updateTableFunction.size() == 0)
        initUpdateTableFunction();

    updateTableFunction[modelType]();
}

QSharedPointer<GameTable> Window_Player::getGameTabelsLoading()
{
    return gameTabelsLoading;
}

void Window_Player::initSetModelFunction()
{
    setModelFunction =
    {
        {ModelTypes::Payments,      [&](QSharedPointer<ModelData> model)  {payments->setModel(model);}},
        {ModelTypes::Credits,       [&](QSharedPointer<ModelData> model)  {playerCredits->setModel(model);}}
    };
}

void Window_Player::initUpdateTableFunction()
{
    updateTableFunction =
    {
        {ModelTypes::Payments,      [&]()  {payments->update();}},
        {ModelTypes::Credits,       [&]()  {playerCredits->update();}}
    };
}

void Window_Player::rendering_GameTablesTab()
{
    gameTabelsLoading = QSharedPointer<GameTable>::create();
    ui->tabWidget->addTab(gameTabelsLoading.data(), "");
}

void Window_Player::rendering_PlayerCreditsTab()
{
    playerCredits = QSharedPointer<PlayerCredits>::create();
    ui->tabWidget->addTab(playerCredits.data(), "");
}

void Window_Player::rendering_PaymentsTab()
{
    payments = QSharedPointer<PlayerPayments>::create();
    ui->tabWidget->addTab(payments.data(), "");
}
