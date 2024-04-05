#include "window_player.h"
#include "ui_window_player.h"

#include "Gui/form.h"

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

    PacketTypes packettype = PacketTypes::P_SendTables;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
}

Window_Player::~Window_Player()
{
    delete ui;
}

void Window_Player::assigningValues()
{
    buttonSwitchingTab.push_back(ui->activeTables);
    buttonSwitchingTab.push_back(ui->replenish);
    buttonSwitchingTab.push_back(ui->credits);

    selectedButton =
    {
        {ui->activeTables, ui->label},
        {ui->replenish, ui->label_2},
        {ui->credits, ui->label_3}
    };
}

void Window_Player::completionTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    rendering_WelcomeTab();
}

void Window_Player::rendering_WelcomeTab()
{
    welcomeTab = QSharedPointer<Welcome>::create(fullName);
    ui->tabWidget->addTab(welcomeTab.data(), "");
}

void Window_Player::uploadingPhotoPlaer()
{
    QPixmap photo = uploadingUserPhoto(":/photos/resources/TestStuffPhoto.jpg");

    ui->photo->setScaledContents(true);
    ui->photo->setPixmap(photo);
}

void Window_Player::settingUserInformation()
{
    ui->fullNamePlayer->setText(fullName);
    uploadingPhotoPlaer();
}

void Window_Player::connects()
{
    connect(ui->activeTables, &QPushButton::clicked, this, &Window_Player::on_activeTables_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &Window_Player::on_buttonExit_clicked);
    connect(ui->credits, &QPushButton::clicked, this, &Window_Player::on_credits_clicked);
    connect(ui->replenish, &QPushButton::clicked, this, &Window_Player::on_replenish_clicked);
}

void Window_Player::on_activeTables_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Player::on_credits_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Player::on_replenish_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Player::setTabels()
{
    //тут послать сигнал на виджет со столами

    //для проверки что столы пришли
    for(QSharedPointer<Table> table : Table::getTables())
    {
        Form* test = new Form(ui->tabWidget);
        test->show();
        qDebug() << "Стол с игрой: " + table->getGame().getNameGame();
    }
}
