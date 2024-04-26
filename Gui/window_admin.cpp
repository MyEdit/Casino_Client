#include "window_admin.h"
#include "ui_window_admin.h"

QWidget* WindowTracker::activeWindow = nullptr;

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

void Window_Admin::connects()
{
    connect(ui->activeTables, &QPushButton::clicked, this, &Window_Admin::on_activeTables_clicked);
    connect(ui->users, &QPushButton::clicked, this, &Window_Admin::on_users_clicked);
    connect(ui->buttonExit, &QPushButton::clicked, this, &Window_Admin::on_buttonExit_clicked);
    connect(ui->stuffUsers, &QPushButton::clicked, this, &Window_Admin::on_stuffUsers_clicked);
    connect(ui->banList, &QPushButton::clicked, this, &Window_Admin::on_banList_clicked);
    connect(ui->credits, &QPushButton::clicked, this, &Window_Admin::on_credits_clicked);
    connect(ui->payments, &QPushButton::clicked, this, &Window_Admin::on_payments_clicked);
}

void Window_Admin::settingUserInformation()
{
    ui->fullNameEmployee->setText(fullName);
    ui->post->setText(definingrRole());
    uploadingPhotoEmployee();
}

const QString Window_Admin::definingrRole()
{
    QString nameRole;

    switch (role)
    {
    case Roles::Admin:
    {
        nameRole = "Администратор";
        break;
    }
    case Roles::TableManager:
    {
        nameRole = "Роспорядитель столов";
        break;
    }
    default:
    {
        nameRole = "Не известная роль";
        break;
    }
    }

    return nameRole;
}

void Window_Admin::uploadingPhotoEmployee()
{
    QSharedPointer<QPixmap> photo = uploadingUserPhoto(P_Authorization::getStuffuser()->getPhoto());

    ui->photo->setScaledContents(true);
    ui->photo->setPixmap(*photo);
}

void Window_Admin::assigningValues()
{
    buttonSwitchingTab.push_back(ui->activeTables);
    buttonSwitchingTab.push_back(ui->users);
    buttonSwitchingTab.push_back(ui->stuffUsers);
    buttonSwitchingTab.push_back(ui->banList);
    buttonSwitchingTab.push_back(ui->credits);
    buttonSwitchingTab.push_back(ui->payments);

    selectedButton =
    {
        {ui->activeTables, ui->label_2},
        {ui->users, ui->label_3},
        {ui->stuffUsers, ui->label_4},
        {ui->banList, ui->label_5},
        {ui->credits, ui->label},
        {ui->payments, ui->label_6}
    };
}

void Window_Admin::setModel_UsersTab(QSharedPointer<ModelData> model)
{
    users->setModel(model);
}

void Window_Admin::setModel_ActiveTablesTab(QSharedPointer<ModelData> model)
{
    activeTables->setModel(model);
}

void Window_Admin::setModel_BanListTab(QSharedPointer<ModelData> model)
{
    banList->setModel(model);
}

void Window_Admin::setModel_StuffUsersTab(QSharedPointer<ModelData> model)
{
    stuffUsers->setModel(model);
}

void Window_Admin::setModel_CreditsTab(QSharedPointer<ModelData> model)
{
    credits->setModel(model);
}

void Window_Admin::setModel_PaymentsTab(QSharedPointer<ModelData> model)
{
    payments->setModel(model);
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

/////////////////РЕНДЕР/////////////////

void Window_Admin::completionTabWidget()
{
    ui->tabWidget->tabBar()->hide();

    if(role == Roles::User)
    {
        rendoringForUser();
    }

    if(role == Roles::TableManager)
    {
        rendoringForTableManager();
    }

    if(role == Roles::Admin)
    {
        rendoringForAdmin();
    }
}

void Window_Admin::rendoringForTableManager()
{
    rendering_WelcomeTab();
    rendering_ActiveTablesTab();
    rendering_UsersTab();
    rendering_BanListTab();

    ui->stuffUsers->hide();
    ui->credits->hide();
    ui->payments->hide();
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
}

void Window_Admin::rendoringForUser()
{
    rendering_WelcomeTab();

    ui->activeTables->hide();
    ui->users->hide();
    ui->stuffUsers->hide();
    ui->banList->hide();
    ui->stuffUsers->hide();
    ui->credits->hide();
    ui->payments->hide();
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
