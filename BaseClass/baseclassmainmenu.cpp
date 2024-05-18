#include "baseclassmainmenu.h"
#include "Gui/window_auth.h"

QMap<Roles, QString> BaseClassMainMenu::nameRole;

BaseClassMainMenu::BaseClassMainMenu(QWidget *parent) : QMainWindow(parent) {}

void BaseClassMainMenu::settingVisual()
{
    QMap<QPushButton*, QLabel*>::iterator i;
    for (i = selectedButton.begin(); i != selectedButton.end(); i++)
        i.value()->setVisible(false);
}

void BaseClassMainMenu::changeUser()
{
    //P_Authorization::adminW = nullptr;
    //P_Authorization::playerW = nullptr;
    //Window_Auth* w = new Window_Auth();
    //WindowTracker::activeWindow = w;
    //w->show();
    //delete this;


    NetworkClient::onServerDisconnected();
}

/////////////////СОБЫТИЯ/////////////////

void BaseClassMainMenu::onNavigationsButton_clicked()
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

void BaseClassMainMenu::on_buttonExit_clicked()
{
    close();
}

/////////////////РЕНДЕР/////////////////

void BaseClassMainMenu::prepareStyleSheets()
{
    inactiveButtonStyleSheet = "QPushButton {"
                               "background: transparent;"
                               "border: none;"
                               "color: rgb(255, 255, 255);"
                               "padding: 5px;"
                               "text-align: left;}"
                               "QPushButton:hover {font-weight: bold;}";

    activeButtonStyleSheet = "QPushButton {"
                             "background-color: rgb(255, 255, 255);"
                             "border-top-left-radius: 10px;"
                             "border-bottom-left-radius: 10px;"
                             "color: rgb(51, 41, 123);"
                             "padding: 5px;"
                             "text-align: left;}";

    nameRole =
    {
        {Roles::Admin, "Администратор"},
        {Roles::TableManager, "Распорядитель столов"}
    };
}

QSharedPointer<QPixmap> BaseClassMainMenu::uploadingUserPhoto(QSharedPointer<QByteArray> data)
{
    QPixmap photo;
    photo.loadFromData(*data);

    if(photo.isNull())
        return nullptr;

    QSharedPointer<QPixmap> roundedPhoto(new QPixmap(photo.size()));
    roundedPhoto->fill(Qt::transparent);
    QPainterPath path;
    path.addRoundedRect(0, 0, photo.width(), photo.height(), photo.width() / 2, photo.height() / 2);

    QPainter painter(roundedPhoto.get());
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, photo);

    return roundedPhoto;
}

QString BaseClassMainMenu::getTextRole(Roles roles)
{
    return nameRole[roles];
}

Roles BaseClassMainMenu::getRole(const QString &textRole)
{
    Roles role = Roles::None;

    for (auto it = nameRole.begin(); it != nameRole.end(); it++)
    {
        if(it.value() == textRole)
            role = it.key();
    }

    return role;
}

void BaseClassMainMenu::settingWindowPosition()
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

/////////////////ИВЕНТЫ/////////////////

void BaseClassMainMenu::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    WindowTracker::activeWindow = this;
}
