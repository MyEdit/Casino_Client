/********************************************************************************
** Form generated from reading UI file 'f_profit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_PROFIT_H
#define UI_F_PROFIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_F_Profit
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QPushButton *date;
    QWidget *categoryDate;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *oneDate;
    QDateEdit *specificDate;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *yourLimitsDate;
    QDateEdit *dateStart;
    QLabel *label_2;
    QDateEdit *dateEnd;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *resetDate;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *reset;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *applyFilter;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *F_Profit)
    {
        if (F_Profit->objectName().isEmpty())
            F_Profit->setObjectName(QString::fromUtf8("F_Profit"));
        F_Profit->resize(365, 353);
        F_Profit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(F_Profit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(F_Profit);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 345, 291));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        date = new QPushButton(scrollAreaWidgetContents);
        date->setObjectName(QString::fromUtf8("date"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        date->setFont(font);
        date->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}"));

        verticalLayout_2->addWidget(date);

        categoryDate = new QWidget(scrollAreaWidgetContents);
        categoryDate->setObjectName(QString::fromUtf8("categoryDate"));
        categoryDate->setStyleSheet(QString::fromUtf8("#categoryDate\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: rgb(198, 198, 198);\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(categoryDate);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        oneDate = new QCheckBox(categoryDate);
        oneDate->setObjectName(QString::fromUtf8("oneDate"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(oneDate->sizePolicy().hasHeightForWidth());
        oneDate->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        oneDate->setFont(font1);

        horizontalLayout_3->addWidget(oneDate);

        specificDate = new QDateEdit(categoryDate);
        specificDate->setObjectName(QString::fromUtf8("specificDate"));
        specificDate->setFont(font1);

        horizontalLayout_3->addWidget(specificDate);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        yourLimitsDate = new QCheckBox(categoryDate);
        yourLimitsDate->setObjectName(QString::fromUtf8("yourLimitsDate"));
        yourLimitsDate->setFont(font1);

        horizontalLayout_2->addWidget(yourLimitsDate);

        dateStart = new QDateEdit(categoryDate);
        dateStart->setObjectName(QString::fromUtf8("dateStart"));
        dateStart->setFont(font1);
        dateStart->setFrame(true);
        dateStart->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateStart->setCorrectionMode(QAbstractSpinBox::CorrectToPreviousValue);
        dateStart->setTimeSpec(Qt::LocalTime);

        horizontalLayout_2->addWidget(dateStart);

        label_2 = new QLabel(categoryDate);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        dateEnd = new QDateEdit(categoryDate);
        dateEnd->setObjectName(QString::fromUtf8("dateEnd"));
        dateEnd->setFont(font1);

        horizontalLayout_2->addWidget(dateEnd);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_2);

        resetDate = new QPushButton(categoryDate);
        resetDate->setObjectName(QString::fromUtf8("resetDate"));
        sizePolicy.setHeightForWidth(resetDate->sizePolicy().hasHeightForWidth());
        resetDate->setSizePolicy(sizePolicy);
        resetDate->setFont(font1);
        resetDate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"text-decoration: underline;\n"
"}"));

        verticalLayout_5->addWidget(resetDate);


        verticalLayout_2->addWidget(categoryDate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reset = new QPushButton(F_Profit);
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

        applyFilter = new QPushButton(F_Profit);
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


        retranslateUi(F_Profit);

        QMetaObject::connectSlotsByName(F_Profit);
    } // setupUi

    void retranslateUi(QDialog *F_Profit)
    {
        F_Profit->setWindowTitle(QApplication::translate("F_Profit", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\277\321\200\320\270\320\261\321\213\320\273\320\270", nullptr));
        date->setText(QApplication::translate("F_Profit", "- \320\224\320\260\321\202\320\260", nullptr));
        oneDate->setText(QString());
        yourLimitsDate->setText(QApplication::translate("F_Profit", "\321\201", nullptr));
        label_2->setText(QApplication::translate("F_Profit", "\320\277\320\276", nullptr));
        resetDate->setText(QApplication::translate("F_Profit", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        reset->setText(QApplication::translate("F_Profit", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        applyFilter->setText(QApplication::translate("F_Profit", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Profit: public Ui_F_Profit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_PROFIT_H
