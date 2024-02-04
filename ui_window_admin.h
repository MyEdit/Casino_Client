/********************************************************************************
** Form generated from reading UI file 'window_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_ADMIN_H
#define UI_WINDOW_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Admin
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_Admin)
    {
        if (Window_Admin->objectName().isEmpty())
            Window_Admin->setObjectName(QString::fromUtf8("Window_Admin"));
        Window_Admin->resize(640, 480);
        menubar = new QMenuBar(Window_Admin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Window_Admin->setMenuBar(menubar);
        centralwidget = new QWidget(Window_Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Window_Admin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Window_Admin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window_Admin->setStatusBar(statusbar);

        retranslateUi(Window_Admin);

        QMetaObject::connectSlotsByName(Window_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Admin)
    {
        Window_Admin->setWindowTitle(QApplication::translate("Window_Admin", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Admin: public Ui_Window_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ADMIN_H
