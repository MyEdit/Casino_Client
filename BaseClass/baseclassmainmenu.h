#ifndef BASECLASSMAINMENU_H
#define BASECLASSMAINMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QPainter>
#include <QGuiApplication>
#include <QRect>
#include <QScreen>
#include <QSharedPointer>
#include <QTabBar>
#include "Utils/windowtracker.h"
#include "Network/PacketTypes.h"
#include "Gui/TabWidgets/welcome.h"

class BaseClassMainMenu : public QMainWindow
{
    Q_OBJECT

protected:
    QString fullName;
    QString inactiveButtonStyleSheet;
    QString activeButtonStyleSheet;
    QVector<QPushButton*> buttonSwitchingTab;
    QMap<QPushButton*, QLabel*> selectedButton;
    QSharedPointer<Welcome> welcomeTab;
    static QMap<Roles, QString> nameRole;

public:
    explicit BaseClassMainMenu(QWidget *parent = nullptr);
    static QSharedPointer<QPixmap> uploadingUserPhoto(QSharedPointer<QByteArray> data);
    static QString getTextRole(Roles roles);
    static Roles getRole(const QString& textRole);

protected:
    void onNavigationsButton_clicked();
    void settingWindowPosition();
    void changeEvent(QEvent* event);
    void prepareStyleSheets();
    void settingVisual();
    void changeUser();
    virtual void assigningValues() = 0;
    virtual void completionTabWidget() = 0;
    virtual void settingUserInformation() = 0;
    virtual void connects() = 0;
    virtual void rendering_WelcomeTab() = 0;

protected slots:
    void on_buttonExit_clicked();
};

#endif // BASECLASSMAINMENU_H
