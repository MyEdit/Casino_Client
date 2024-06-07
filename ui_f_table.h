/********************************************************************************
** Form generated from reading UI file 'f_table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_TABLE_H
#define UI_F_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_F_Table
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QPushButton *minBet;
    QWidget *categoryMinBet;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *minBetStart0end100;
    QCheckBox *minBetStart100end200;
    QCheckBox *minBetStart200end300;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *yourLimitsMinBet;
    QLineEdit *minBetStart;
    QLabel *label_2;
    QLineEdit *minBetEnd;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *resetMinBet;
    QPushButton *maxPlayers;
    QWidget *categoryMaxPlayers;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *quantity2;
    QCheckBox *quantity3;
    QCheckBox *quantity4;
    QCheckBox *quantity5;
    QCheckBox *quantity6;
    QCheckBox *quantity7;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *yourLimitsMaxPlayers;
    QLineEdit *maxPlayersStart;
    QLabel *label;
    QLineEdit *maxPlayersEnd;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *resetMaxPlayers;
    QPushButton *minBalance;
    QWidget *categoryMinBalance;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *minBalanceStart0end100;
    QCheckBox *minBalanceStart100end200;
    QCheckBox *minBalanceStart200end300;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *yourLimitsMinBalance;
    QLineEdit *minBalanceStart;
    QLabel *label_3;
    QLineEdit *minBalanceEnd;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *resetMinBalance;
    QPushButton *nameGame;
    QWidget *categoryNameGame;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *nameBlackJack;
    QCheckBox *nameDevytka;
    QPushButton *resetNameGame;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *reset;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *applyFilter;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *F_Table)
    {
        if (F_Table->objectName().isEmpty())
            F_Table->setObjectName(QString::fromUtf8("F_Table"));
        F_Table->resize(442, 475);
        F_Table->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(F_Table);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(F_Table);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 408, 995));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        minBet = new QPushButton(scrollAreaWidgetContents);
        minBet->setObjectName(QString::fromUtf8("minBet"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        minBet->setFont(font);
        minBet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}"));

        verticalLayout_2->addWidget(minBet);

        categoryMinBet = new QWidget(scrollAreaWidgetContents);
        categoryMinBet->setObjectName(QString::fromUtf8("categoryMinBet"));
        categoryMinBet->setStyleSheet(QString::fromUtf8("#categoryMinBet\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: rgb(198, 198, 198);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(categoryMinBet);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        minBetStart0end100 = new QCheckBox(categoryMinBet);
        minBetStart0end100->setObjectName(QString::fromUtf8("minBetStart0end100"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minBetStart0end100->sizePolicy().hasHeightForWidth());
        minBetStart0end100->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        minBetStart0end100->setFont(font1);

        verticalLayout_5->addWidget(minBetStart0end100);

        minBetStart100end200 = new QCheckBox(categoryMinBet);
        minBetStart100end200->setObjectName(QString::fromUtf8("minBetStart100end200"));
        sizePolicy.setHeightForWidth(minBetStart100end200->sizePolicy().hasHeightForWidth());
        minBetStart100end200->setSizePolicy(sizePolicy);
        minBetStart100end200->setFont(font1);

        verticalLayout_5->addWidget(minBetStart100end200);

        minBetStart200end300 = new QCheckBox(categoryMinBet);
        minBetStart200end300->setObjectName(QString::fromUtf8("minBetStart200end300"));
        sizePolicy.setHeightForWidth(minBetStart200end300->sizePolicy().hasHeightForWidth());
        minBetStart200end300->setSizePolicy(sizePolicy);
        minBetStart200end300->setFont(font1);

        verticalLayout_5->addWidget(minBetStart200end300);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        yourLimitsMinBet = new QCheckBox(categoryMinBet);
        yourLimitsMinBet->setObjectName(QString::fromUtf8("yourLimitsMinBet"));
        yourLimitsMinBet->setFont(font1);

        horizontalLayout_2->addWidget(yourLimitsMinBet);

        minBetStart = new QLineEdit(categoryMinBet);
        minBetStart->setObjectName(QString::fromUtf8("minBetStart"));
        minBetStart->setFont(font1);
        minBetStart->setFrame(false);

        horizontalLayout_2->addWidget(minBetStart);

        label_2 = new QLabel(categoryMinBet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        minBetEnd = new QLineEdit(categoryMinBet);
        minBetEnd->setObjectName(QString::fromUtf8("minBetEnd"));
        minBetEnd->setFont(font1);
        minBetEnd->setFrame(false);

        horizontalLayout_2->addWidget(minBetEnd);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_2);

        resetMinBet = new QPushButton(categoryMinBet);
        resetMinBet->setObjectName(QString::fromUtf8("resetMinBet"));
        sizePolicy.setHeightForWidth(resetMinBet->sizePolicy().hasHeightForWidth());
        resetMinBet->setSizePolicy(sizePolicy);
        resetMinBet->setFont(font1);
        resetMinBet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"text-decoration: underline;\n"
"}"));

        verticalLayout_5->addWidget(resetMinBet);


        verticalLayout_2->addWidget(categoryMinBet);

        maxPlayers = new QPushButton(scrollAreaWidgetContents);
        maxPlayers->setObjectName(QString::fromUtf8("maxPlayers"));
        maxPlayers->setFont(font);
        maxPlayers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}"));

        verticalLayout_2->addWidget(maxPlayers);

        categoryMaxPlayers = new QWidget(scrollAreaWidgetContents);
        categoryMaxPlayers->setObjectName(QString::fromUtf8("categoryMaxPlayers"));
        categoryMaxPlayers->setStyleSheet(QString::fromUtf8("#categoryMaxPlayers\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: rgb(198, 198, 198);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(categoryMaxPlayers);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        quantity2 = new QCheckBox(categoryMaxPlayers);
        quantity2->setObjectName(QString::fromUtf8("quantity2"));
        sizePolicy.setHeightForWidth(quantity2->sizePolicy().hasHeightForWidth());
        quantity2->setSizePolicy(sizePolicy);
        quantity2->setFont(font1);

        verticalLayout_4->addWidget(quantity2);

        quantity3 = new QCheckBox(categoryMaxPlayers);
        quantity3->setObjectName(QString::fromUtf8("quantity3"));
        sizePolicy.setHeightForWidth(quantity3->sizePolicy().hasHeightForWidth());
        quantity3->setSizePolicy(sizePolicy);
        quantity3->setFont(font1);

        verticalLayout_4->addWidget(quantity3);

        quantity4 = new QCheckBox(categoryMaxPlayers);
        quantity4->setObjectName(QString::fromUtf8("quantity4"));
        sizePolicy.setHeightForWidth(quantity4->sizePolicy().hasHeightForWidth());
        quantity4->setSizePolicy(sizePolicy);
        quantity4->setFont(font1);

        verticalLayout_4->addWidget(quantity4);

        quantity5 = new QCheckBox(categoryMaxPlayers);
        quantity5->setObjectName(QString::fromUtf8("quantity5"));
        sizePolicy.setHeightForWidth(quantity5->sizePolicy().hasHeightForWidth());
        quantity5->setSizePolicy(sizePolicy);
        quantity5->setFont(font1);

        verticalLayout_4->addWidget(quantity5);

        quantity6 = new QCheckBox(categoryMaxPlayers);
        quantity6->setObjectName(QString::fromUtf8("quantity6"));
        sizePolicy.setHeightForWidth(quantity6->sizePolicy().hasHeightForWidth());
        quantity6->setSizePolicy(sizePolicy);
        quantity6->setFont(font1);

        verticalLayout_4->addWidget(quantity6);

        quantity7 = new QCheckBox(categoryMaxPlayers);
        quantity7->setObjectName(QString::fromUtf8("quantity7"));
        sizePolicy.setHeightForWidth(quantity7->sizePolicy().hasHeightForWidth());
        quantity7->setSizePolicy(sizePolicy);
        quantity7->setFont(font1);

        verticalLayout_4->addWidget(quantity7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        yourLimitsMaxPlayers = new QCheckBox(categoryMaxPlayers);
        yourLimitsMaxPlayers->setObjectName(QString::fromUtf8("yourLimitsMaxPlayers"));
        yourLimitsMaxPlayers->setFont(font1);

        horizontalLayout_4->addWidget(yourLimitsMaxPlayers);

        maxPlayersStart = new QLineEdit(categoryMaxPlayers);
        maxPlayersStart->setObjectName(QString::fromUtf8("maxPlayersStart"));
        maxPlayersStart->setFont(font1);

        horizontalLayout_4->addWidget(maxPlayersStart);

        label = new QLabel(categoryMaxPlayers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        maxPlayersEnd = new QLineEdit(categoryMaxPlayers);
        maxPlayersEnd->setObjectName(QString::fromUtf8("maxPlayersEnd"));
        maxPlayersEnd->setFont(font1);

        horizontalLayout_4->addWidget(maxPlayersEnd);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_4);

        resetMaxPlayers = new QPushButton(categoryMaxPlayers);
        resetMaxPlayers->setObjectName(QString::fromUtf8("resetMaxPlayers"));
        sizePolicy.setHeightForWidth(resetMaxPlayers->sizePolicy().hasHeightForWidth());
        resetMaxPlayers->setSizePolicy(sizePolicy);
        resetMaxPlayers->setFont(font1);
        resetMaxPlayers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"text-decoration: underline;\n"
"}"));

        verticalLayout_4->addWidget(resetMaxPlayers);


        verticalLayout_2->addWidget(categoryMaxPlayers);

        minBalance = new QPushButton(scrollAreaWidgetContents);
        minBalance->setObjectName(QString::fromUtf8("minBalance"));
        minBalance->setFont(font);
        minBalance->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}"));

        verticalLayout_2->addWidget(minBalance);

        categoryMinBalance = new QWidget(scrollAreaWidgetContents);
        categoryMinBalance->setObjectName(QString::fromUtf8("categoryMinBalance"));
        categoryMinBalance->setStyleSheet(QString::fromUtf8("#categoryMinBalance\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: rgb(198, 198, 198);\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(categoryMinBalance);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        minBalanceStart0end100 = new QCheckBox(categoryMinBalance);
        minBalanceStart0end100->setObjectName(QString::fromUtf8("minBalanceStart0end100"));
        sizePolicy.setHeightForWidth(minBalanceStart0end100->sizePolicy().hasHeightForWidth());
        minBalanceStart0end100->setSizePolicy(sizePolicy);
        minBalanceStart0end100->setFont(font1);

        verticalLayout_6->addWidget(minBalanceStart0end100);

        minBalanceStart100end200 = new QCheckBox(categoryMinBalance);
        minBalanceStart100end200->setObjectName(QString::fromUtf8("minBalanceStart100end200"));
        sizePolicy.setHeightForWidth(minBalanceStart100end200->sizePolicy().hasHeightForWidth());
        minBalanceStart100end200->setSizePolicy(sizePolicy);
        minBalanceStart100end200->setFont(font1);

        verticalLayout_6->addWidget(minBalanceStart100end200);

        minBalanceStart200end300 = new QCheckBox(categoryMinBalance);
        minBalanceStart200end300->setObjectName(QString::fromUtf8("minBalanceStart200end300"));
        sizePolicy.setHeightForWidth(minBalanceStart200end300->sizePolicy().hasHeightForWidth());
        minBalanceStart200end300->setSizePolicy(sizePolicy);
        minBalanceStart200end300->setFont(font1);

        verticalLayout_6->addWidget(minBalanceStart200end300);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        yourLimitsMinBalance = new QCheckBox(categoryMinBalance);
        yourLimitsMinBalance->setObjectName(QString::fromUtf8("yourLimitsMinBalance"));
        yourLimitsMinBalance->setFont(font1);

        horizontalLayout_3->addWidget(yourLimitsMinBalance);

        minBalanceStart = new QLineEdit(categoryMinBalance);
        minBalanceStart->setObjectName(QString::fromUtf8("minBalanceStart"));
        minBalanceStart->setFont(font1);
        minBalanceStart->setFrame(false);

        horizontalLayout_3->addWidget(minBalanceStart);

        label_3 = new QLabel(categoryMinBalance);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_3->addWidget(label_3);

        minBalanceEnd = new QLineEdit(categoryMinBalance);
        minBalanceEnd->setObjectName(QString::fromUtf8("minBalanceEnd"));
        minBalanceEnd->setFont(font1);
        minBalanceEnd->setFrame(false);

        horizontalLayout_3->addWidget(minBalanceEnd);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_3);

        resetMinBalance = new QPushButton(categoryMinBalance);
        resetMinBalance->setObjectName(QString::fromUtf8("resetMinBalance"));
        sizePolicy.setHeightForWidth(resetMinBalance->sizePolicy().hasHeightForWidth());
        resetMinBalance->setSizePolicy(sizePolicy);
        resetMinBalance->setFont(font1);
        resetMinBalance->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"text-decoration: underline;\n"
"}"));

        verticalLayout_6->addWidget(resetMinBalance);


        verticalLayout_2->addWidget(categoryMinBalance);

        nameGame = new QPushButton(scrollAreaWidgetContents);
        nameGame->setObjectName(QString::fromUtf8("nameGame"));
        nameGame->setFont(font);
        nameGame->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}"));

        verticalLayout_2->addWidget(nameGame);

        categoryNameGame = new QWidget(scrollAreaWidgetContents);
        categoryNameGame->setObjectName(QString::fromUtf8("categoryNameGame"));
        categoryNameGame->setStyleSheet(QString::fromUtf8("#categoryNameGame\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: rgb(198, 198, 198);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(categoryNameGame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        nameBlackJack = new QCheckBox(categoryNameGame);
        nameBlackJack->setObjectName(QString::fromUtf8("nameBlackJack"));
        sizePolicy.setHeightForWidth(nameBlackJack->sizePolicy().hasHeightForWidth());
        nameBlackJack->setSizePolicy(sizePolicy);
        nameBlackJack->setFont(font1);

        verticalLayout_3->addWidget(nameBlackJack);

        nameDevytka = new QCheckBox(categoryNameGame);
        nameDevytka->setObjectName(QString::fromUtf8("nameDevytka"));
        sizePolicy.setHeightForWidth(nameDevytka->sizePolicy().hasHeightForWidth());
        nameDevytka->setSizePolicy(sizePolicy);
        nameDevytka->setFont(font1);

        verticalLayout_3->addWidget(nameDevytka);

        resetNameGame = new QPushButton(categoryNameGame);
        resetNameGame->setObjectName(QString::fromUtf8("resetNameGame"));
        sizePolicy.setHeightForWidth(resetNameGame->sizePolicy().hasHeightForWidth());
        resetNameGame->setSizePolicy(sizePolicy);
        resetNameGame->setFont(font1);
        resetNameGame->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"text-decoration: underline;\n"
"}"));

        verticalLayout_3->addWidget(resetNameGame);


        verticalLayout_2->addWidget(categoryNameGame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reset = new QPushButton(F_Table);
        reset->setObjectName(QString::fromUtf8("reset"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        reset->setFont(font3);
        reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(reset);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        applyFilter = new QPushButton(F_Table);
        applyFilter->setObjectName(QString::fromUtf8("applyFilter"));
        applyFilter->setFont(font3);
        applyFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(applyFilter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(F_Table);

        QMetaObject::connectSlotsByName(F_Table);
    } // setupUi

    void retranslateUi(QDialog *F_Table)
    {
        F_Table->setWindowTitle(QApplication::translate("F_Table", "\320\244\320\270\320\273\321\214\321\202\321\200 \321\201\321\202\320\276\320\273\320\276\320\262", nullptr));
        F_Table->setWindowFilePath(QString());
        minBet->setText(QApplication::translate("F_Table", "- \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        minBetStart0end100->setText(QApplication::translate("F_Table", "\320\276\321\202 0 \320\264\320\276 100", nullptr));
        minBetStart100end200->setText(QApplication::translate("F_Table", "\320\276\321\202 100 \320\264\320\276 200", nullptr));
        minBetStart200end300->setText(QApplication::translate("F_Table", "\320\276\321\202 200 \320\264\320\276 300", nullptr));
        yourLimitsMinBet->setText(QApplication::translate("F_Table", "\320\276\321\202", nullptr));
        label_2->setText(QApplication::translate("F_Table", "\320\264\320\276", nullptr));
        resetMinBet->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        maxPlayers->setText(QApplication::translate("F_Table", "- \320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274 \320\270\320\263\321\200\320\276\320\272\320\276\320\262", nullptr));
        quantity2->setText(QApplication::translate("F_Table", "2", nullptr));
        quantity3->setText(QApplication::translate("F_Table", "3", nullptr));
        quantity4->setText(QApplication::translate("F_Table", "4", nullptr));
        quantity5->setText(QApplication::translate("F_Table", "5", nullptr));
        quantity6->setText(QApplication::translate("F_Table", "6", nullptr));
        quantity7->setText(QApplication::translate("F_Table", "7", nullptr));
        yourLimitsMaxPlayers->setText(QApplication::translate("F_Table", "\320\276\321\202", nullptr));
        label->setText(QApplication::translate("F_Table", "\320\264\320\276", nullptr));
        resetMaxPlayers->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        minBalance->setText(QApplication::translate("F_Table", "- \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\261\320\260\320\273\320\260\320\275\321\201", nullptr));
        minBalanceStart0end100->setText(QApplication::translate("F_Table", "\320\276\321\202 0 \320\264\320\276 100", nullptr));
        minBalanceStart100end200->setText(QApplication::translate("F_Table", "\320\276\321\202 100 \320\264\320\276 200", nullptr));
        minBalanceStart200end300->setText(QApplication::translate("F_Table", "\320\276\321\202 200 \320\264\320\276 300", nullptr));
        yourLimitsMinBalance->setText(QApplication::translate("F_Table", "\320\276\321\202", nullptr));
        label_3->setText(QApplication::translate("F_Table", "\320\264\320\276", nullptr));
        resetMinBalance->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        nameGame->setText(QApplication::translate("F_Table", "- \320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\270\320\263\321\200\321\213", nullptr));
        nameBlackJack->setText(QApplication::translate("F_Table", "BlackJack", nullptr));
        nameDevytka->setText(QApplication::translate("F_Table", "\320\224\320\265\320\262\321\217\321\202\320\272\320\260", nullptr));
        resetNameGame->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        reset->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        applyFilter->setText(QApplication::translate("F_Table", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Table: public Ui_F_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_TABLE_H
