/********************************************************************************
** Form generated from reading UI file 'creategametable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGAMETABLE_H
#define UI_CREATEGAMETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateGameTable
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *numPlayers;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *minBid;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *minRateIncreaseStep;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *minBudget;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *selectGame;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *create;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QLabel *tableHasBeenCreated;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *CreateGameTable)
    {
        if (CreateGameTable->objectName().isEmpty())
            CreateGameTable->setObjectName(QString::fromUtf8("CreateGameTable"));
        CreateGameTable->resize(671, 427);
        CreateGameTable->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(CreateGameTable);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CreateGameTable);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        numPlayers = new QComboBox(CreateGameTable);
        numPlayers->setObjectName(QString::fromUtf8("numPlayers"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        numPlayers->setFont(font1);

        horizontalLayout->addWidget(numPlayers);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(CreateGameTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        minBid = new QLineEdit(CreateGameTable);
        minBid->setObjectName(QString::fromUtf8("minBid"));
        minBid->setMaximumSize(QSize(200, 16777215));
        minBid->setFont(font1);
        minBid->setMaxLength(9);

        horizontalLayout_2->addWidget(minBid);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(CreateGameTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        minRateIncreaseStep = new QLineEdit(CreateGameTable);
        minRateIncreaseStep->setObjectName(QString::fromUtf8("minRateIncreaseStep"));
        minRateIncreaseStep->setMaximumSize(QSize(200, 16777215));
        minRateIncreaseStep->setFont(font1);
        minRateIncreaseStep->setMaxLength(9);

        horizontalLayout_3->addWidget(minRateIncreaseStep);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(CreateGameTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        minBudget = new QLineEdit(CreateGameTable);
        minBudget->setObjectName(QString::fromUtf8("minBudget"));
        minBudget->setMaximumSize(QSize(200, 16777215));
        minBudget->setFont(font1);
        minBudget->setMaxLength(9);

        horizontalLayout_4->addWidget(minBudget);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        selectGame = new QComboBox(CreateGameTable);
        selectGame->setObjectName(QString::fromUtf8("selectGame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectGame->sizePolicy().hasHeightForWidth());
        selectGame->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        selectGame->setFont(font2);

        horizontalLayout_5->addWidget(selectGame);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        create = new QPushButton(CreateGameTable);
        create->setObjectName(QString::fromUtf8("create"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        create->setFont(font3);
        create->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
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
"}\n"
"\n"
"/* \n"
"(QPushButton {\n"
"    background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:1, stop:0.393258 rgba(247, 84, 225, 255), stop:1 rgba(106, 90, 205, 255));\n"
"    border-radius: 10px;\n"
"    padding-left: 35px;\n"
"    padding-right: 35px;\n"
"    padding-top: 5px;\n"
"    padding-bottom: 5px;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:1, stop:0.393258 rgba(220, 60, 190, 255), stop:1 rgba(90, 76, 175, 255));\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}\n"
"*/\n"
""));

        horizontalLayout_7->addWidget(create);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        tableHasBeenCreated = new QLabel(CreateGameTable);
        tableHasBeenCreated->setObjectName(QString::fromUtf8("tableHasBeenCreated"));
        tableHasBeenCreated->setEnabled(true);
        sizePolicy.setHeightForWidth(tableHasBeenCreated->sizePolicy().hasHeightForWidth());
        tableHasBeenCreated->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        tableHasBeenCreated->setFont(font4);

        horizontalLayout_6->addWidget(tableHasBeenCreated);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(CreateGameTable);

        QMetaObject::connectSlotsByName(CreateGameTable);
    } // setupUi

    void retranslateUi(QWidget *CreateGameTable)
    {
        CreateGameTable->setWindowTitle(QApplication::translate("CreateGameTable", "Form", nullptr));
        label->setText(QApplication::translate("CreateGameTable", "\320\232\320\276\320\273-\320\262\320\276 \320\270\320\263\321\200\320\276\320\272\320\276\320\262: ", nullptr));
        label_2->setText(QApplication::translate("CreateGameTable", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260: ", nullptr));
        label_3->setText(QApplication::translate("CreateGameTable", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\210\320\260\320\263 \n"
"\320\277\320\276\320\262\321\213\321\210\320\265\320\275\320\270\321\217 \321\201\321\202\320\260\320\262\320\272\320\270: ", nullptr));
        label_4->setText(QApplication::translate("CreateGameTable", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\261\321\216\320\264\320\266\320\265\321\202 \n"
"\320\264\320\273\321\217 \320\275\320\260\321\207\320\260\320\273\320\260 \320\270\320\263\321\200\321\213: ", nullptr));
        create->setText(QApplication::translate("CreateGameTable", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        tableHasBeenCreated->setText(QApplication::translate("CreateGameTable", "\320\241\321\202\320\276\320\273 \321\201\320\276\320\267\320\264\320\260\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGameTable: public Ui_CreateGameTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGAMETABLE_H
