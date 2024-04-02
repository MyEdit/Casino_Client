#include "baseclassmainmenu.h"
BaseClassMainMenu::BaseClassMainMenu(QWidget *parent) : QMainWindow(parent)
{

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

/////////////////РЕНДЕР/////////////////

void BaseClassMainMenu::prepareStyleSheets()
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

void BaseClassMainMenu::uploadingUserPhoto(QLabel* profilePicture, QString url)
{
    QPixmap photo(url);

    QPixmap roundedPhoto(photo.size());
    roundedPhoto.fill(Qt::transparent);
    QPainterPath path;
    path.addRoundedRect(0, 0, photo.width(), photo.height(), photo.width() / 2, photo.height() / 2);

    QPainter painter(&roundedPhoto);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setClipPath(path);

    profilePicture->setScaledContents(true);
    profilePicture->setPixmap(roundedPhoto);
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
