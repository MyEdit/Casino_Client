/********************************************************************************
** Form generated from reading UI file 'add_stuffuser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_STUFFUSER_H
#define UI_ADD_STUFFUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_StuffUser
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelPassword;
    QLineEdit *name;
    QLineEdit *login;
    QLabel *labelRole;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonReset;
    QSpacerItem *horizontalSpacer;
    QPushButton *bottonSave;
    QLabel *labelLogin;
    QComboBox *role;
    QLabel *labelName;
    QLineEdit *password;

    void setupUi(QWidget *Add_StuffUser)
    {
        if (Add_StuffUser->objectName().isEmpty())
            Add_StuffUser->setObjectName(QString::fromUtf8("Add_StuffUser"));
        Add_StuffUser->resize(452, 248);
        gridLayout_2 = new QGridLayout(Add_StuffUser);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPassword = new QLabel(Add_StuffUser);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPassword->sizePolicy().hasHeightForWidth());
        labelPassword->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelPassword->setFont(font);
        labelPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPassword, 2, 0, 1, 1);

        name = new QLineEdit(Add_StuffUser);
        name->setObjectName(QString::fromUtf8("name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        name->setFont(font1);

        gridLayout->addWidget(name, 0, 1, 1, 1);

        login = new QLineEdit(Add_StuffUser);
        login->setObjectName(QString::fromUtf8("login"));
        sizePolicy1.setHeightForWidth(login->sizePolicy().hasHeightForWidth());
        login->setSizePolicy(sizePolicy1);
        login->setFont(font1);

        gridLayout->addWidget(login, 1, 1, 1, 1);

        labelRole = new QLabel(Add_StuffUser);
        labelRole->setObjectName(QString::fromUtf8("labelRole"));
        sizePolicy.setHeightForWidth(labelRole->sizePolicy().hasHeightForWidth());
        labelRole->setSizePolicy(sizePolicy);
        labelRole->setFont(font);
        labelRole->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelRole, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        buttonReset = new QPushButton(Add_StuffUser);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));
        buttonReset->setFont(font1);
        buttonReset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));

        horizontalLayout_4->addWidget(buttonReset);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        bottonSave = new QPushButton(Add_StuffUser);
        bottonSave->setObjectName(QString::fromUtf8("bottonSave"));
        bottonSave->setFont(font1);
        bottonSave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));

        horizontalLayout_4->addWidget(bottonSave);


        gridLayout->addLayout(horizontalLayout_4, 5, 0, 1, 2);

        labelLogin = new QLabel(Add_StuffUser);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));
        sizePolicy.setHeightForWidth(labelLogin->sizePolicy().hasHeightForWidth());
        labelLogin->setSizePolicy(sizePolicy);
        labelLogin->setFont(font);
        labelLogin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelLogin, 1, 0, 1, 1);

        role = new QComboBox(Add_StuffUser);
        role->setObjectName(QString::fromUtf8("role"));
        sizePolicy1.setHeightForWidth(role->sizePolicy().hasHeightForWidth());
        role->setSizePolicy(sizePolicy1);
        role->setFont(font1);

        gridLayout->addWidget(role, 3, 1, 1, 1);

        labelName = new QLabel(Add_StuffUser);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        sizePolicy.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelName, 0, 0, 1, 1);

        password = new QLineEdit(Add_StuffUser);
        password->setObjectName(QString::fromUtf8("password"));
        sizePolicy1.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy1);
        password->setFont(font1);

        gridLayout->addWidget(password, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(Add_StuffUser);

        QMetaObject::connectSlotsByName(Add_StuffUser);
    } // setupUi

    void retranslateUi(QWidget *Add_StuffUser)
    {
        Add_StuffUser->setWindowTitle(QApplication::translate("Add_StuffUser", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        labelPassword->setText(QApplication::translate("Add_StuffUser", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        labelRole->setText(QApplication::translate("Add_StuffUser", "\320\240\320\276\320\273\321\214:", nullptr));
        buttonReset->setText(QApplication::translate("Add_StuffUser", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        bottonSave->setText(QApplication::translate("Add_StuffUser", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        labelLogin->setText(QApplication::translate("Add_StuffUser", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        labelName->setText(QApplication::translate("Add_StuffUser", "\320\244\320\230\320\236:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_StuffUser: public Ui_Add_StuffUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_STUFFUSER_H
