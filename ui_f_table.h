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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *nameGame;
    QWidget *categotyNameGame;
    QVBoxLayout *verticalLayout_3;
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
        F_Table->resize(482, 426);
        F_Table->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);W"));
        verticalLayout = new QVBoxLayout(F_Table);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(F_Table);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 462, 364));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        nameGame = new QPushButton(scrollAreaWidgetContents);
        nameGame->setObjectName(QString::fromUtf8("nameGame"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
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

        categotyNameGame = new QWidget(scrollAreaWidgetContents);
        categotyNameGame->setObjectName(QString::fromUtf8("categotyNameGame"));
        categotyNameGame->setStyleSheet(QString::fromUtf8("#categotyNameGame\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: rgb(198, 198, 198);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(categotyNameGame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        nameBlackJack = new QRadioButton(categotyNameGame);
        nameBlackJack->setObjectName(QString::fromUtf8("nameBlackJack"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        nameBlackJack->setFont(font1);
        nameBlackJack->setStyleSheet(QString::fromUtf8("color: black"));

        verticalLayout_3->addWidget(nameBlackJack);

        nameDevytka = new QRadioButton(categotyNameGame);
        nameDevytka->setObjectName(QString::fromUtf8("nameDevytka"));
        nameDevytka->setFont(font1);
        nameDevytka->setStyleSheet(QString::fromUtf8("color: black"));

        verticalLayout_3->addWidget(nameDevytka);


        verticalLayout_2->addWidget(categotyNameGame);

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
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        reset->setFont(font2);
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
        applyFilter->setFont(font2);
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
        nameGame->setText(QApplication::translate("F_Table", "- \320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\270\320\263\321\200\321\213", nullptr));
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
