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
#include "Utils/windowtracker.h"

class BaseClassMainMenu : public QMainWindow
{
    Q_OBJECT
protected:
    QString fullName;
    QString inactiveButtonStyleSheet;
    QString activeButtonStyleSheet;
    QVector<QPushButton*> buttonSwitchingTab;
    QMap<QPushButton*, QLabel*> selectedButton;

public:
    explicit BaseClassMainMenu(QWidget *parent = nullptr);

protected:
    void onNavigationsButton_clicked();
    void uploadingUserPhoto(QLabel* profilePicture, QString url);
    void settingWindowPosition();
    void changeEvent(QEvent *event);
    void prepareStyleSheets();
    virtual void assigningValues() = 0;
    virtual void completionTabWidget() = 0;
    virtual void settingEmployeeInformation() = 0;
    virtual void connects() = 0;
};

#endif // BASECLASSMAINMENU_H
