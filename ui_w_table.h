/********************************************************************************
** Form generated from reading UI file 'w_table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_TABLE_H
#define UI_W_TABLE_H

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

class Ui_W_Table
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *labelBetStep;
    QLineEdit *InputMinBalance;
    QLineEdit *InputMinBet;
    QLineEdit *InputMaxPlayer;
    QLabel *labelNameGame;
    QComboBox *nameGame;
    QLabel *labelMaxPlayer;
    QLineEdit *InputBetStep;
    QLabel *labelMinBet;
    QLabel *labelMinBalance;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonReset;
    QSpacerItem *horizontalSpacer;
    QPushButton *bottonSave;

    void setupUi(QWidget *W_Table)
    {
        if (W_Table->objectName().isEmpty())
            W_Table->setObjectName(QString::fromUtf8("W_Table"));
        W_Table->resize(472, 317);
        gridLayout_2 = new QGridLayout(W_Table);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelBetStep = new QLabel(W_Table);
        labelBetStep->setObjectName(QString::fromUtf8("labelBetStep"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelBetStep->sizePolicy().hasHeightForWidth());
        labelBetStep->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelBetStep->setFont(font);
        labelBetStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelBetStep, 2, 0, 1, 1);

        InputMinBalance = new QLineEdit(W_Table);
        InputMinBalance->setObjectName(QString::fromUtf8("InputMinBalance"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(InputMinBalance->sizePolicy().hasHeightForWidth());
        InputMinBalance->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        InputMinBalance->setFont(font1);

        gridLayout->addWidget(InputMinBalance, 3, 1, 1, 1);

        InputMinBet = new QLineEdit(W_Table);
        InputMinBet->setObjectName(QString::fromUtf8("InputMinBet"));
        sizePolicy1.setHeightForWidth(InputMinBet->sizePolicy().hasHeightForWidth());
        InputMinBet->setSizePolicy(sizePolicy1);
        InputMinBet->setFont(font1);

        gridLayout->addWidget(InputMinBet, 1, 1, 1, 1);

        InputMaxPlayer = new QLineEdit(W_Table);
        InputMaxPlayer->setObjectName(QString::fromUtf8("InputMaxPlayer"));
        sizePolicy1.setHeightForWidth(InputMaxPlayer->sizePolicy().hasHeightForWidth());
        InputMaxPlayer->setSizePolicy(sizePolicy1);
        InputMaxPlayer->setFont(font1);

        gridLayout->addWidget(InputMaxPlayer, 0, 1, 1, 1);

        labelNameGame = new QLabel(W_Table);
        labelNameGame->setObjectName(QString::fromUtf8("labelNameGame"));
        sizePolicy.setHeightForWidth(labelNameGame->sizePolicy().hasHeightForWidth());
        labelNameGame->setSizePolicy(sizePolicy);
        labelNameGame->setFont(font);
        labelNameGame->setLayoutDirection(Qt::LeftToRight);
        labelNameGame->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelNameGame, 4, 0, 1, 1);

        nameGame = new QComboBox(W_Table);
        nameGame->setObjectName(QString::fromUtf8("nameGame"));
        sizePolicy1.setHeightForWidth(nameGame->sizePolicy().hasHeightForWidth());
        nameGame->setSizePolicy(sizePolicy1);
        nameGame->setFont(font1);

        gridLayout->addWidget(nameGame, 4, 1, 1, 1);

        labelMaxPlayer = new QLabel(W_Table);
        labelMaxPlayer->setObjectName(QString::fromUtf8("labelMaxPlayer"));
        sizePolicy.setHeightForWidth(labelMaxPlayer->sizePolicy().hasHeightForWidth());
        labelMaxPlayer->setSizePolicy(sizePolicy);
        labelMaxPlayer->setFont(font);
        labelMaxPlayer->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelMaxPlayer, 0, 0, 1, 1);

        InputBetStep = new QLineEdit(W_Table);
        InputBetStep->setObjectName(QString::fromUtf8("InputBetStep"));
        sizePolicy1.setHeightForWidth(InputBetStep->sizePolicy().hasHeightForWidth());
        InputBetStep->setSizePolicy(sizePolicy1);
        InputBetStep->setFont(font1);

        gridLayout->addWidget(InputBetStep, 2, 1, 1, 1);

        labelMinBet = new QLabel(W_Table);
        labelMinBet->setObjectName(QString::fromUtf8("labelMinBet"));
        sizePolicy.setHeightForWidth(labelMinBet->sizePolicy().hasHeightForWidth());
        labelMinBet->setSizePolicy(sizePolicy);
        labelMinBet->setFont(font);
        labelMinBet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelMinBet, 1, 0, 1, 1);

        labelMinBalance = new QLabel(W_Table);
        labelMinBalance->setObjectName(QString::fromUtf8("labelMinBalance"));
        sizePolicy.setHeightForWidth(labelMinBalance->sizePolicy().hasHeightForWidth());
        labelMinBalance->setSizePolicy(sizePolicy);
        labelMinBalance->setFont(font);
        labelMinBalance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelMinBalance, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        buttonReset = new QPushButton(W_Table);
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

        bottonSave = new QPushButton(W_Table);
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


        gridLayout->addLayout(horizontalLayout_4, 6, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(W_Table);

        QMetaObject::connectSlotsByName(W_Table);
    } // setupUi

    void retranslateUi(QWidget *W_Table)
    {
        W_Table->setWindowTitle(QApplication::translate("W_Table", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\260", nullptr));
        labelBetStep->setText(QApplication::translate("W_Table", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\210\320\260\320\263 \n"
"\320\277\320\276\320\262\321\213\321\210\320\265\320\275\320\270\321\217 \321\201\321\202\320\260\320\262\320\272\320\270:", nullptr));
        labelNameGame->setText(QApplication::translate("W_Table", "\320\230\320\263\321\200\320\260:", nullptr));
        labelMaxPlayer->setText(QApplication::translate("W_Table", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \n"
"\320\272\320\276\320\273-\320\262\320\276 \320\270\320\263\321\200\320\276\320\272\320\276\320\262:", nullptr));
        labelMinBet->setText(QApplication::translate("W_Table", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        labelMinBalance->setText(QApplication::translate("W_Table", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\261\321\216\320\264\320\266\320\265\321\202:", nullptr));
        buttonReset->setText(QApplication::translate("W_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        bottonSave->setText(QApplication::translate("W_Table", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Table: public Ui_W_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_TABLE_H
