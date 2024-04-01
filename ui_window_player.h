/********************************************************************************
** Form generated from reading UI file 'window_player.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PLAYER_H
#define UI_WINDOW_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Player
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_Player)
    {
        if (Window_Player->objectName().isEmpty())
            Window_Player->setObjectName(QString::fromUtf8("Window_Player"));
        Window_Player->resize(800, 600);
        menubar = new QMenuBar(Window_Player);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Window_Player->setMenuBar(menubar);
        centralwidget = new QWidget(Window_Player);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Window_Player->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Window_Player);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window_Player->setStatusBar(statusbar);

        retranslateUi(Window_Player);

        QMetaObject::connectSlotsByName(Window_Player);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Player)
    {
        Window_Player->setWindowTitle(QApplication::translate("Window_Player", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Player: public Ui_Window_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PLAYER_H
