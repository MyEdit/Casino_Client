/********************************************************************************
** Form generated from reading UI file 'window_auth.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_AUTH_H
#define UI_WINDOW_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Auth
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *textBox_Login;
    QLineEdit *textBox_Password;
    QPushButton *Button_Auth;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window_Auth)
    {
        if (Window_Auth->objectName().isEmpty())
            Window_Auth->setObjectName(QString::fromUtf8("Window_Auth"));
        Window_Auth->resize(745, 452);
        centralwidget = new QWidget(Window_Auth);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-110, -10, 523, 531));
        label->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/Window_Auth_Background.png")));
        label->setScaledContents(true);
        textBox_Login = new QLineEdit(centralwidget);
        textBox_Login->setObjectName(QString::fromUtf8("textBox_Login"));
        textBox_Login->setGeometry(QRect(470, 130, 243, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        textBox_Login->setFont(font);
        textBox_Password = new QLineEdit(centralwidget);
        textBox_Password->setObjectName(QString::fromUtf8("textBox_Password"));
        textBox_Password->setGeometry(QRect(470, 180, 243, 41));
        textBox_Password->setFont(font);
        Button_Auth = new QPushButton(centralwidget);
        Button_Auth->setObjectName(QString::fromUtf8("Button_Auth"));
        Button_Auth->setGeometry(QRect(470, 250, 243, 45));
        Window_Auth->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window_Auth);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 745, 21));
        Window_Auth->setMenuBar(menubar);
        statusbar = new QStatusBar(Window_Auth);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window_Auth->setStatusBar(statusbar);

        retranslateUi(Window_Auth);

        QMetaObject::connectSlotsByName(Window_Auth);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Auth)
    {
        Window_Auth->setWindowTitle(QApplication::translate("Window_Auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QString());
        Button_Auth->setText(QApplication::translate("Window_Auth", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Auth: public Ui_Window_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_AUTH_H
