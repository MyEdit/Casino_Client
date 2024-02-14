#include "window_admin.h"
#include "ui_window_admin.h"

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
    buttonSwitchingTab.push_back(ui->buttonExistingTables);
    buttonSwitchingTab.push_back(ui->buttonAllUsers);
    buttonSwitchingTab.push_back(ui->buttonStaff);
    buttonSwitchingTab.push_back(ui->buttonBlackList);
    buttonSwitchingTab.push_back(ui->buttonLoanApplocations);

    selectedButton =
    {
        {ui->buttonExistingTables, ui->label_2},
        {ui->buttonAllUsers, ui->label_3},
        {ui->buttonStaff, ui->label_4},
        {ui->buttonBlackList, ui->label_5},
        {ui->buttonLoanApplocations, ui->label},
        {ui->pushButton, ui->label_6}
    };
}

void Window_Admin::setModel_AllUsersTab(ModelData model)
{
//    allUsersTab->setModel(model);
}

void Window_Admin::setModel_ExistingTab(ModelData model)
{
    existingTablesTab->setModel(model);
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

void Window_Admin::on_buttonExistingTables_clicked()
{
    ui->tabWidget->setCurrentWidget(existingTablesTab.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_buttonAllUsers_clicked()
{
    ui->tabWidget->setCurrentWidget(allUsersTab.get());
    onNavigationsButton_clicked();
}

void Window_Admin::on_buttonExit_clicked()
{
    close();
}

void Window_Admin::on_buttonStaff_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Admin::on_buttonBlackList_clicked()
{
    onNavigationsButton_clicked();
}

void Window_Admin::on_buttonLoanApplocations_clicked()
{
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
    rendering_CreateGameTableTab();
    rendering_ExistingTablesTab();
    rendering_AllUsersTab();
}

void Window_Admin::rendering_CreateGameTableTab()
{
    createGameTableTab = QSharedPointer<CreateGameTable>::create();
    ui->tabWidget->addTab(createGameTableTab.data(), "С");
}

void Window_Admin::rendering_ExistingTablesTab()
{
    existingTablesTab = QSharedPointer<ExistingTables>::create();
    ui->tabWidget->addTab(existingTablesTab.data(), "");
}

void Window_Admin::rendering_AllUsersTab()
{
    allUsersTab = QSharedPointer<AllUsers>::create();
    ui->tabWidget->addTab(allUsersTab.data(), "");
}

void Window_Admin::rendering_WelcomeTab()
{
    welcomeTab = QSharedPointer<Welcome>::create("Администратор");
    ui->tabWidget->addTab(welcomeTab.data(), "");
}

/////////////////ИВЕНТЫ/////////////////

void Window_Admin::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);

    PacketTypes packettype = PacketTypes::P_SendModel;

    //Запрашиваю у сервера модель с данными "Пользователи"
//    ModelTypes users = ModelTypes::Users;
//    ModelLoadingType modelLoadingTypeUsers = ModelLoadingType::Central;
//    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
//    NetworkClient::sendToServer(&modelLoadingTypeUsers, sizeof(ModelLoadingType));
//    NetworkClient::sendToServer(&users, sizeof(ModelTypes));

    //Запрашиваю у сервера модель с данными "Игровые столы"
    int offset = 0;
    ModelTypes existingTables = ModelTypes::ExistingTables;
    ModelLoadingType modelLoadingTypeExistingTables = ModelLoadingType::Central;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modelLoadingTypeExistingTables, sizeof(ModelLoadingType));
    NetworkClient::sendToServer(&existingTables, sizeof(ModelTypes));
    NetworkClient::sendToServer(&offset, sizeof(int));

    modelLoadingTypeExistingTables = ModelLoadingType::Prev;
    offset = -50;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modelLoadingTypeExistingTables, sizeof(ModelLoadingType));
    NetworkClient::sendToServer(&existingTables, sizeof(ModelTypes));
    NetworkClient::sendToServer(&offset, sizeof(int));

    modelLoadingTypeExistingTables = ModelLoadingType::Next;
    offset = 50;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modelLoadingTypeExistingTables, sizeof(ModelLoadingType));
    NetworkClient::sendToServer(&existingTables, sizeof(ModelTypes));
    NetworkClient::sendToServer(&offset, sizeof(int));
}

