#include "window_admin.h"
#include "ui_window_admin.h"

QWidget* WindowTracker::activeWindow = nullptr;

Window_Admin::Window_Admin(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window_Admin)
{
    ui->setupUi(this);

    prepareStyleSheets();
    assigningValues();
    completionTabWidget();
    uploadingPhotoEmployee();
    settingWindowPosition();

    QMap<QPushButton*, QLabel*>::iterator i;
    for (i = selectedButton.begin(); i != selectedButton.end(); i++)
        i.value()->setVisible(false);

    ui->tabWidget->setCurrentWidget(welcomeTab.get());
}

Window_Admin::~Window_Admin()
{
    delete ui;
}

void Window_Admin::uploadingPhotoEmployee()
{
    QPixmap photo(":/photos/resources/TestStuffPhoto.jpg");

    QPixmap roundedPhoto(photo.size());
    roundedPhoto.fill(Qt::transparent);
    QPainterPath path;
    path.addRoundedRect(0, 0, photo.width(), photo.height(), photo.width() / 2, photo.height() / 2);

    QPainter painter(&roundedPhoto);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, photo);

    ui->photo->setScaledContents(true);
    ui->photo->setPixmap(roundedPhoto);
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

void Window_Admin::setModel_UsersTab(ModelData model)
{
    users->setModel(model);
}

void Window_Admin::setModel_ActiveTablesTab(ModelData model)
{
    activeTables->setModel(model);
}

void Window_Admin::setModel_BanListTab(ModelData model)
{
    banList->setModel(model);
}

void Window_Admin::setModel_StuffUsersTab(ModelData model)
{
    stuffUsers->setModel(model);
}

void Window_Admin::setModel_CreditsTab(ModelData model)
{
    credits->setModel(model);
}

void Window_Admin::setModel_PaymentsTab(ModelData model)
{
    payments->setModel(model);
}

void Window_Admin::settingWindowPosition()
{
    QScreen *primaryScreen = QGuiApplication::primaryScreen();

    //Вычисление размера окна относительно размера экрана
    QRect screenGeometry = primaryScreen->geometry();
    int screenWidth = screenGeometry.width() / 1.5;
    int screenHeight = screenGeometry.height() / 1.4;
    resize(screenWidth, screenHeight);

    //Вычисление положения окна относительно рабочей области
    QRect availableGeometry = primaryScreen->availableGeometry();
    int x = (availableGeometry.width() - width()) / 2;
    int y = (availableGeometry.height() - height()) / 2;
    move(x, y);
}

/////////////////СОБЫТИЯ/////////////////

void Window_Admin::onNavigationsButton_clicked()
{
    QPushButton* selectButton = (QPushButton*)sender();

    for(QPushButton* button : buttonSwitchingTab)
    {
        button->setStyleSheet(inactiveButtonStyleSheet);
        selectedButton[button]->setVisible(false);
    }

    selectButton->setStyleSheet(activeButtonStyleSheet);
    selectedButton[selectButton]->setVisible(true);
}

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

void Window_Admin::on_buttonExit_clicked()
{
    close();
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

void Window_Admin::prepareStyleSheets()
{
    inactiveButtonStyleSheet = "QPushButton {"
                               "background: transparent; "
                               "border: none; "
                               "color: rgb(255, 255, 255); "
                               "padding: 5px; "
                               "text-align: left;}";

    activeButtonStyleSheet = "QPushButton {"
                             "background-color: rgb(255, 255, 255);"
                             "border-top-left-radius: 10px;"
                             "border-bottom-left-radius: 10px;"
                             "color: rgb(51, 41, 123);"
                             "padding: 5px;"
                             "text-align: left;}";
}

void Window_Admin::completionTabWidget()
{
    ui->tabWidget->tabBar()->hide();

    rendering_WelcomeTab();
    rendering_ActiveTablesTab();
    rendering_UsersTab();
    rendering_BanListTab();
    rendering_StuffUsersTab();
    rendering_CreditsTab();
    rendering_PaymentsTab();
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
    welcomeTab = QSharedPointer<Welcome>::create("Администратор");
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

/////////////////ИВЕНТЫ/////////////////
void Window_Admin::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    WindowTracker::activeWindow = this;
}
