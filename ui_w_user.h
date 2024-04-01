/********************************************************************************
** Form generated from reading UI file 'w_user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_USER_H
#define UI_W_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_User
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelBalance;
    QLabel *labelName;
    QLabel *labelPassword;
    QLineEdit *InputName;
    QLineEdit *InputLogin;
    QLineEdit *InputPassword;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonReset;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonSave;
    QLabel *labelPassport;
    QLabel *labelLogin;
    QLineEdit *InputPassport;
    QLineEdit *InputBalance;

    void setupUi(QWidget *W_User)
    {
        if (W_User->objectName().isEmpty())
            W_User->setObjectName(QString::fromUtf8("W_User"));
        W_User->resize(468, 309);
        gridLayout_2 = new QGridLayout(W_User);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelBalance = new QLabel(W_User);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelBalance->setFont(font);
        labelBalance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelBalance, 2, 0, 1, 1);

        labelName = new QLabel(W_User);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelName, 0, 0, 1, 1);

        labelPassword = new QLabel(W_User);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));
        sizePolicy.setHeightForWidth(labelPassword->sizePolicy().hasHeightForWidth());
        labelPassword->setSizePolicy(sizePolicy);
        labelPassword->setFont(font);
        labelPassword->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPassword, 4, 0, 1, 1);

        InputName = new QLineEdit(W_User);
        InputName->setObjectName(QString::fromUtf8("InputName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(InputName->sizePolicy().hasHeightForWidth());
        InputName->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        InputName->setFont(font1);

        gridLayout->addWidget(InputName, 0, 1, 1, 1);

        InputLogin = new QLineEdit(W_User);
        InputLogin->setObjectName(QString::fromUtf8("InputLogin"));
        sizePolicy1.setHeightForWidth(InputLogin->sizePolicy().hasHeightForWidth());
        InputLogin->setSizePolicy(sizePolicy1);
        InputLogin->setFont(font1);

        gridLayout->addWidget(InputLogin, 3, 1, 1, 1);

        InputPassword = new QLineEdit(W_User);
        InputPassword->setObjectName(QString::fromUtf8("InputPassword"));
        sizePolicy1.setHeightForWidth(InputPassword->sizePolicy().hasHeightForWidth());
        InputPassword->setSizePolicy(sizePolicy1);
        InputPassword->setFont(font1);

        gridLayout->addWidget(InputPassword, 4, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        buttonReset = new QPushButton(W_User);
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

        buttonSave = new QPushButton(W_User);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));
        buttonSave->setFont(font1);
        buttonSave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_4->addWidget(buttonSave);


        gridLayout->addLayout(horizontalLayout_4, 6, 0, 1, 2);

        labelPassport = new QLabel(W_User);
        labelPassport->setObjectName(QString::fromUtf8("labelPassport"));
        labelPassport->setFont(font);
        labelPassport->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPassport, 1, 0, 1, 1);

        labelLogin = new QLabel(W_User);
        labelLogin->setObjectName(QString::fromUtf8("labelLogin"));
        sizePolicy.setHeightForWidth(labelLogin->sizePolicy().hasHeightForWidth());
        labelLogin->setSizePolicy(sizePolicy);
        labelLogin->setFont(font);
        labelLogin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelLogin, 3, 0, 1, 1);

        InputPassport = new QLineEdit(W_User);
        InputPassport->setObjectName(QString::fromUtf8("InputPassport"));
        sizePolicy1.setHeightForWidth(InputPassport->sizePolicy().hasHeightForWidth());
        InputPassport->setSizePolicy(sizePolicy1);
        InputPassport->setFont(font1);

        gridLayout->addWidget(InputPassport, 1, 1, 1, 1);

        InputBalance = new QLineEdit(W_User);
        InputBalance->setObjectName(QString::fromUtf8("InputBalance"));
        sizePolicy1.setHeightForWidth(InputBalance->sizePolicy().hasHeightForWidth());
        InputBalance->setSizePolicy(sizePolicy1);
        InputBalance->setFont(font1);

        gridLayout->addWidget(InputBalance, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(W_User);

        QMetaObject::connectSlotsByName(W_User);
    } // setupUi

    void retranslateUi(QWidget *W_User)
    {
        W_User->setWindowTitle(QApplication::translate("W_User", "Form", nullptr));
        labelBalance->setText(QApplication::translate("W_User", "\320\221\320\260\320\273\320\260\320\275\321\201", nullptr));
        labelName->setText(QApplication::translate("W_User", "\320\244\320\230\320\236:", nullptr));
        labelPassword->setText(QApplication::translate("W_User", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        buttonReset->setText(QApplication::translate("W_User", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        buttonSave->setText(QApplication::translate("W_User", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        labelPassport->setText(QApplication::translate("W_User", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\265 \n"
"\320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        labelLogin->setText(QApplication::translate("W_User", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        InputPassport->setInputMask(QApplication::translate("W_User", "0000 000000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_User: public Ui_W_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_USER_H
