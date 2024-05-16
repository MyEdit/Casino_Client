#include "window_admin.h"
#include "ui_window_admin.h"
#include "Gui/window_auth.h"

//QWidget* WindowTracker::activeWindow = nullptr;

Window_Admin::Window_Admin(QWidget *parent) : BaseClassMainMenu(parent), ui(new Ui::Window_Admin)
{
    ui->setupUi(this);
    fullName = P_Authorization::getActualUser()->getName();
    role = P_Authorization::getActualUser()->getRole();

    prepareStyleSheets();
    assigningValues();
    completionTabWidget();
    settingUserInformation();
    settingWindowPosition();
    connects();
    settingVisual();

    ui->tabWidget->setCurrentWidget(welcomeTab.get());
}

Window_Admin::~Window_Admin()
{
    delete ui;
}

void Window_Admin::setModel(QSharedPointer<ModelData> set)
{
    if (setModelFunction.size() == 0)
        initSetModelFunction();

    setModelFunction[set->modelTypes](set);
}

void Window_Admin::updateTable(ModelTypes modelType)
{
    if (updateTableFunction.size() == 0)
        initUpdateTableFunction();

    updateTableFunction[modelType]();
}

void Window_Admin::connects()
{
    connect(ui->activeTables, &QPushButton::clicked, this, &Window_Admin::on_activeTables_clicked);
    connect(ui->users, &QPushButton::clicked, this, &Window_Admin::on_users_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &Window_Admin::on_buttonExit_clicked);
    connect(ui->stuffUsers, &QPushButton::clicked, this, &Window_Admin::on_stuffUsers_clicked);
    connect(ui->banList, &QPushButton::clicked, this, &Window_Admin::on_banList_clicked);
    connect(ui->credits, &QPushButton::clicked, this, &Window_Admin::on_credits_clicked);
    connect(ui->payments, &QPushButton::clicked, this, &Window_Admin::on_payments_clicked);
    connect(ui->profit, &QPushButton::clicked, this, &Window_Admin::on_profit_clicked);
    connect(ui->buttonChangeUser, &QPushButton::clicked, this, &Window_Admin::changeUser);
}

void Window_Admin::initSetModelFunction()
{
    setModelFunction =
    {
        {ModelTypes::Users,         [&](QSharedPointer<ModelData> model)  {users->setModel(model);}},
        {ModelTypes::ActiveTables,  [&](QSharedPointer<ModelData> model)  {activeTables->setModel(model);}},
        {ModelTypes::Banlist,       [&](QSharedPointer<ModelData> model)  {banList->setModel(model);}},
        {ModelTypes::StuffUsers,    [&](QSharedPointer<ModelData> model)  {stuffUsers->setModel(model);}},
        {ModelTypes::Payments,      [&](QSharedPointer<ModelData> model)  {payments->setModel(model);}},
        {ModelTypes::Credits,       [&](QSharedPointer<ModelData> model)  {credits->setModel(model);}},
        {ModelTypes::Profit,        [&](QSharedPointer<ModelData> model)  {profit->setModel(model);}}
    };
}

void Window_Admin::initUpdateTableFunction()
{
    updateTableFunction =
    {
        {ModelTypes::Users,         [&]()  {users->update();}},
        {ModelTypes::ActiveTables,  [&]()  {activeTables->update();}},
        {ModelTypes::Banlist,       [&]()  {banList->update();}},
        {ModelTypes::StuffUsers,    [&]()  {stuffUsers->update();}},
        {ModelTypes::Payments,      [&]()  {payments->update();}},
        {ModelTypes::Credits,       [&]()  {credits->update();}},
        {ModelTypes::Profit,        [&]()  {profit->update();}}
    };
}

void Window_Admin::settingUserInformation()
{
    ui->fullNameEmployee->setText(fullName);
    ui->post->setText(definingrRole());
    uploadingPhotoEmployee();
}

const QString Window_Admin::definingrRole()
{
    return nameRole[role];
}

void Window_Admin::uploadingPhotoEmployee()
{
    QSharedPointer<QPixmap> photo = uploadingUserPhoto(P_Authorization::getStuffuser()->getPhoto());

    ui->photo->setScaledContents(true);

    if(photo)
        ui->photo->setPixmap(*photo);
    else
        ui->photo->hide();
}

void Window_Admin::assigningValues()
{
    buttonSwitchingTab.push_back(ui->activeTables);
    buttonSwitchingTab.push_back(ui->users);
    buttonSwitchingTab.push_back(ui->stuffUsers);
    buttonSwitchingTab.push_back(ui->banList);
    buttonSwitchingTab.push_back(ui->credits);
    buttonSwitchingTab.push_back(ui->payments);
    buttonSwitchingTab.push_back(ui->profit);

    selectedButton =
    {
        {ui->activeTables, ui->label_2},
        {ui->users, ui->label_3},
        {ui->stuffUsers, ui->label_4},
        {ui->banList, ui->label_5},
        {ui->credits, ui->label},
        {ui->payments, ui->label_6},
        {ui->profit, ui->label_7}
    };

    nameRole =
    {
        {Roles::Admin, "Администратор"},
        {Roles::TableManager, "Роспорядитель столов"}
    };
}

/////////////////СОБЫТИЯ/////////////////

void Window_Admin::on_activeTables_clicked()
{
    ui->tabWidget->setCurrentWidget(activeTables.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_users_clicked()
{
    ui->tabWidget->setCurrentWidget(users.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_stuffUsers_clicked()
{
    ui->tabWidget->setCurrentWidget(stuffUsers.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_banList_clicked()
{
    ui->tabWidget->setCurrentWidget(banList.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_credits_clicked()
{
    ui->tabWidget->setCurrentWidget(credits.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_payments_clicked()
{
    ui->tabWidget->setCurrentWidget(payments.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_profit_clicked()
{
    ui->tabWidget->setCurrentWidget(profit.get());
    onNavigationsButton_clicked();
}

/////////////////РЕНДЕР/////////////////

void Window_Admin::completionTabWidget()
{
    ui->tabWidget->tabBar()->hide();

    if(role == Roles::TableManager)
        rendoringForTableManager();
    else if(role == Roles::Admin)
        rendoringForAdmin();
}

void Window_Admin::rendoringForTableManager()
{
    rendering_WelcomeTab();
    rendering_ActiveTablesTab();
    rendering_PaymentsTab();
    rendering_ProfitTab();

    ui->stuffUsers->hide();
    ui->credits->hide();
    ui->users->hide();
    ui->banList->hide();
}

void Window_Admin::rendoringForAdmin()
{
    rendering_WelcomeTab();
    rendering_ActiveTablesTab();
    rendering_UsersTab();
    rendering_BanListTab();
    rendering_StuffUsersTab();
    rendering_CreditsTab();
    rendering_PaymentsTab();
    rendering_ProfitTab();
}

void Window_Admin::rendering_ActiveTablesTab()
{
    activeTables = QSharedPointer<ActiveTables>::create();
    ui->tabWidget->addTab(activeTables.data(), "");
}

void Window_Admin::rendering_UsersTab()
{
    users = QSharedPointer<Users>::create();
    ui->tabWidget->addTab(users.data(), "");
}

void Window_Admin::rendering_WelcomeTab()
{
    welcomeTab = QSharedPointer<Welcome>::create(definingrRole() + " - " + P_Authorization::getStuffuser()->getName());
    ui->tabWidget->addTab(welcomeTab.data(), "");
}

void Window_Admin::rendering_BanListTab()
{
    banList = QSharedPointer<BanList>::create();
    ui->tabWidget->addTab(banList.data(), "");
}

void Window_Admin::rendering_StuffUsersTab()
{
    stuffUsers = QSharedPointer<StuffUsers>::create();
    ui->tabWidget->addTab(stuffUsers.data(), "");
}

void Window_Admin::rendering_CreditsTab()
{
    credits = QSharedPointer<Credits>::create();
    ui->tabWidget->addTab(credits.data(), "");
}

void Window_Admin::rendering_PaymentsTab()
{
    payments = QSharedPointer<Payments>::create();
    ui->tabWidget->addTab(payments.data(), "");
}

void Window_Admin::rendering_ProfitTab()
{
    profit = QSharedPointer<Profit>::create();
    ui->tabWidget->addTab(profit.data(), "");
}
