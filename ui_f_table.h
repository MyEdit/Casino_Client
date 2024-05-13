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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QRadioButton *allMinBet;
    QRadioButton *start0end100;
    QRadioButton *start100end200;
    QRadioButton *start200end300;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *yourLimitsMinBet;
    QLineEdit *startMinBet;
    QLabel *label_2;
    QLineEdit *endMinBet;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *maxPlayers;
    QWidget *categoryMaxPlayers;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *allMaxPlayers;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *specQuantityMaxPlayrs;
    QComboBox *quantityMaxPlayrs;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *yourLimitsMaxPlayers;
    QLineEdit *startMaxPlayers;
    QLabel *label;
    QLineEdit *endMaxPlayers;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *nameGame;
    QWidget *categoryNameGame;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *allNameGame;
    QRadioButton *nameBlackJack;
    QRadioButton *nameDevytka;
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 408, 581));
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
        allMinBet = new QRadioButton(categoryMinBet);
        allMinBet->setObjectName(QString::fromUtf8("allMinBet"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        allMinBet->setFont(font1);

        verticalLayout_5->addWidget(allMinBet);

        start0end100 = new QRadioButton(categoryMinBet);
        start0end100->setObjectName(QString::fromUtf8("start0end100"));
        start0end100->setFont(font1);

        verticalLayout_5->addWidget(start0end100);

        start100end200 = new QRadioButton(categoryMinBet);
        start100end200->setObjectName(QString::fromUtf8("start100end200"));
        start100end200->setFont(font1);

        verticalLayout_5->addWidget(start100end200);

        start200end300 = new QRadioButton(categoryMinBet);
        start200end300->setObjectName(QString::fromUtf8("start200end300"));
        start200end300->setFont(font1);

        verticalLayout_5->addWidget(start200end300);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        yourLimitsMinBet = new QRadioButton(categoryMinBet);
        yourLimitsMinBet->setObjectName(QString::fromUtf8("yourLimitsMinBet"));
        yourLimitsMinBet->setFont(font1);

        horizontalLayout_2->addWidget(yourLimitsMinBet);

        startMinBet = new QLineEdit(categoryMinBet);
        startMinBet->setObjectName(QString::fromUtf8("startMinBet"));
        startMinBet->setFont(font1);
        startMinBet->setFrame(false);

        horizontalLayout_2->addWidget(startMinBet);

        label_2 = new QLabel(categoryMinBet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        endMinBet = new QLineEdit(categoryMinBet);
        endMinBet->setObjectName(QString::fromUtf8("endMinBet"));
        endMinBet->setFont(font1);
        endMinBet->setFrame(false);

        horizontalLayout_2->addWidget(endMinBet);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_2);


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
        allMaxPlayers = new QRadioButton(categoryMaxPlayers);
        allMaxPlayers->setObjectName(QString::fromUtf8("allMaxPlayers"));
        allMaxPlayers->setFont(font1);

        verticalLayout_4->addWidget(allMaxPlayers);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        specQuantityMaxPlayrs = new QRadioButton(categoryMaxPlayers);
        specQuantityMaxPlayrs->setObjectName(QString::fromUtf8("specQuantityMaxPlayrs"));

        horizontalLayout_3->addWidget(specQuantityMaxPlayrs);

        quantityMaxPlayrs = new QComboBox(categoryMaxPlayers);
        quantityMaxPlayrs->addItem(QString());
        quantityMaxPlayrs->addItem(QString());
        quantityMaxPlayrs->addItem(QString());
        quantityMaxPlayrs->addItem(QString());
        quantityMaxPlayrs->addItem(QString());
        quantityMaxPlayrs->addItem(QString());
        quantityMaxPlayrs->setObjectName(QString::fromUtf8("quantityMaxPlayrs"));
        quantityMaxPlayrs->setFont(font1);

        horizontalLayout_3->addWidget(quantityMaxPlayrs);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        yourLimitsMaxPlayers = new QRadioButton(categoryMaxPlayers);
        yourLimitsMaxPlayers->setObjectName(QString::fromUtf8("yourLimitsMaxPlayers"));
        yourLimitsMaxPlayers->setFont(font1);

        horizontalLayout_4->addWidget(yourLimitsMaxPlayers);

        startMaxPlayers = new QLineEdit(categoryMaxPlayers);
        startMaxPlayers->setObjectName(QString::fromUtf8("startMaxPlayers"));
        startMaxPlayers->setFont(font1);

        horizontalLayout_4->addWidget(startMaxPlayers);

        label = new QLabel(categoryMaxPlayers);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout_4->addWidget(label);

        endMaxPlayers = new QLineEdit(categoryMaxPlayers);
        endMaxPlayers->setObjectName(QString::fromUtf8("endMaxPlayers"));
        endMaxPlayers->setFont(font1);

        horizontalLayout_4->addWidget(endMaxPlayers);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(categoryMaxPlayers);

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
        allNameGame = new QRadioButton(categoryNameGame);
        allNameGame->setObjectName(QString::fromUtf8("allNameGame"));
        allNameGame->setFont(font1);

        verticalLayout_3->addWidget(allNameGame);

        nameBlackJack = new QRadioButton(categoryNameGame);
        nameBlackJack->setObjectName(QString::fromUtf8("nameBlackJack"));
        nameBlackJack->setFont(font1);

        verticalLayout_3->addWidget(nameBlackJack);

        nameDevytka = new QRadioButton(categoryNameGame);
        nameDevytka->setObjectName(QString::fromUtf8("nameDevytka"));
        nameDevytka->setFont(font1);
        nameDevytka->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(nameDevytka);


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
        F_Table->setWindowFilePath(QApplication::translate("F_Table", "z", nullptr));
        minBet->setText(QApplication::translate("F_Table", "- \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        allMinBet->setText(QApplication::translate("F_Table", "\320\235\320\265\321\202 \320\273\320\270\320\274\320\270\321\202\320\260", nullptr));
        start0end100->setText(QApplication::translate("F_Table", "\320\276\321\202 0 \320\264\320\276 100", nullptr));
        start100end200->setText(QApplication::translate("F_Table", "\320\276\321\202 100 \320\264\320\276 200", nullptr));
        start200end300->setText(QApplication::translate("F_Table", "\320\276\321\202 200 \320\264\320\276 300", nullptr));
        yourLimitsMinBet->setText(QApplication::translate("F_Table", "\320\276\321\202", nullptr));
        label_2->setText(QApplication::translate("F_Table", "\320\264\320\276", nullptr));
        maxPlayers->setText(QApplication::translate("F_Table", "- \320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274 \320\270\320\263\321\200\320\276\320\272\320\276\320\262", nullptr));
        allMaxPlayers->setText(QApplication::translate("F_Table", "\320\235\320\265 \320\262\320\260\320\266\320\275\320\276", nullptr));
        specQuantityMaxPlayrs->setText(QString());
        quantityMaxPlayrs->setItemText(0, QApplication::translate("F_Table", "2", nullptr));
        quantityMaxPlayrs->setItemText(1, QApplication::translate("F_Table", "3", nullptr));
        quantityMaxPlayrs->setItemText(2, QApplication::translate("F_Table", "4", nullptr));
        quantityMaxPlayrs->setItemText(3, QApplication::translate("F_Table", "5", nullptr));
        quantityMaxPlayrs->setItemText(4, QApplication::translate("F_Table", "6", nullptr));
        quantityMaxPlayrs->setItemText(5, QApplication::translate("F_Table", "7", nullptr));

        yourLimitsMaxPlayers->setText(QApplication::translate("F_Table", "\320\276\321\202", nullptr));
        label->setText(QApplication::translate("F_Table", "\320\264\320\276", nullptr));
        nameGame->setText(QApplication::translate("F_Table", "- \320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\270\320\263\321\200\321\213", nullptr));
        allNameGame->setText(QApplication::translate("F_Table", "\320\222\321\201\320\265", nullptr));
        nameBlackJack->setText(QApplication::translate("F_Table", "BlackJack", nullptr));
        nameDevytka->setText(QApplication::translate("F_Table", "\320\224\320\265\320\262\321\217\321\202\320\272\320\260", nullptr));
        reset->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        applyFilter->setText(QApplication::translate("F_Table", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Table: public Ui_F_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_TABLE_H
