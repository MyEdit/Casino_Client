#include "window_admin.h"
#include "ui_window_admin.h"
#include <QPainter>
#include <QBitmap>

Window_Admin::Window_Admin(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window_Admin)
{
    ui->setupUi(this);

    prepareStyleSheets();
    assigningValues();
    completionTabWidget();
    uploadingPhotoEmployee();

    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
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
    //По хорошему этот кусок кода переделать на цикл, в C# у всех элементов было свойство tag, в котором можно было хранить доп инфу об объекте, может и тут есть аналог, если есть то можно сделать так
    /*
    for(QPushButton* button : ВсеКнопкиНаФорме)
    {
        if(button.tag.equals("NavButton"))
        {
            buttonSwitchingTab.push_back(button);
        }
    }
    */
    buttonSwitchingTab.push_back(ui->buttonCreateTable);
    buttonSwitchingTab.push_back(ui->buttonExistingTables);
    buttonSwitchingTab.push_back(ui->buttonAllUsers);

    selectedButton =
    {
        {ui->buttonCreateTable, ui->label},
        {ui->buttonExistingTables, ui->label_2},
        {ui->buttonAllUsers, ui->label_3}
    };
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

void Window_Admin::on_buttonCreateTable_clicked()
{
    ui->tabWidget->setCurrentWidget(createGameTableTab.get());
    onNavigationsButton_clicked();
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

    rendering_CreateGameTableTab();
    rendering_ExistingTablesTab();
    rendering_AllUsersTab();
}

void Window_Admin::rendering_CreateGameTableTab()
{
    createGameTableTab = QSharedPointer<CreateGameTable>::create();
    ui->tabWidget->addTab(createGameTableTab.data(), "Создать стол");
}

void Window_Admin::rendering_ExistingTablesTab()
{
    existingTablesTab = QSharedPointer<ExistingTables>::create();
    ui->tabWidget->addTab(existingTablesTab.data(), "Созданые столы");
}

void Window_Admin::rendering_AllUsersTab()
{
    allUsersTab = QSharedPointer<AllUsers>::create();
    ui->tabWidget->addTab(allUsersTab.data(), "Созданые столы");
}
