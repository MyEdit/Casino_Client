/********************************************************************************
** Form generated from reading UI file 'playerpayments.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERPAYMENTS_H
#define UI_PLAYERPAYMENTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerPayments
{
public:
    QGridLayout *gridLayout;
    QWidget *replenishmentWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLabel *labelInformation;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonPay;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLabel *label_7;
    QWidget *cardHolderWidget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLineEdit *lineEdit_9;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_9;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_7;
    QLabel *label_12;
    QLineEdit *lineEdit_5;
    QLabel *label_11;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_14;
    QWidget *otherPaymentMethodsWidget;
    QGridLayout *gridLayout_3;
    QPushButton *buttonSBP;
    QPushButton *buttonYOOMoney;
    QPushButton *buttonVKPay;
    QPushButton *buttonMTS;
    QPushButton *buttonSber;
    QPushButton *buttonWebMoney;
    QLabel *label_2;
    QWidget *searchWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelHistoriPayments;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_Search;
    QCheckBox *checkBox_Sorting;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *refreshData;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QComboBox *searchColumn;
    QLineEdit *searchText;
    QCheckBox *checkBox;
    QPushButton *pushButton_search;
    QPushButton *clearSearch;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *sorting;
    QLabel *label_19;
    QComboBox *sortingColumn;
    QLabel *label_20;
    QComboBox *typeSorting;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_15;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_8;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_4;
    QLabel *labelCurrentPage;
    QLabel *label_5;
    QLabel *labelMaxPage;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_6;
    QLineEdit *pageNumberToNavigate;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *nextButton;

    void setupUi(QWidget *PlayerPayments)
    {
        if (PlayerPayments->objectName().isEmpty())
            PlayerPayments->setObjectName(QString::fromUtf8("PlayerPayments"));
        PlayerPayments->resize(1158, 669);
        PlayerPayments->setStyleSheet(QString::fromUtf8(".searchLayout\n"
"{\n"
"	background-color: rgb(170, 255, 0);\n"
"}"));
        gridLayout = new QGridLayout(PlayerPayments);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        replenishmentWidget = new QWidget(PlayerPayments);
        replenishmentWidget->setObjectName(QString::fromUtf8("replenishmentWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(replenishmentWidget->sizePolicy().hasHeightForWidth());
        replenishmentWidget->setSizePolicy(sizePolicy);
        replenishmentWidget->setStyleSheet(QString::fromUtf8("#replenishmentWidget\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"}"));
        gridLayout_2 = new QGridLayout(replenishmentWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(replenishmentWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        lineEdit->setFont(font);

        gridLayout_2->addWidget(lineEdit, 1, 1, 1, 1);

        labelInformation = new QLabel(replenishmentWidget);
        labelInformation->setObjectName(QString::fromUtf8("labelInformation"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(8);
        labelInformation->setFont(font1);
        labelInformation->setAlignment(Qt::AlignCenter);
        labelInformation->setWordWrap(true);

        gridLayout_2->addWidget(labelInformation, 4, 0, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        buttonPay = new QPushButton(replenishmentWidget);
        buttonPay->setObjectName(QString::fromUtf8("buttonPay"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        buttonPay->setFont(font2);
        buttonPay->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding: 3px;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));

        gridLayout_2->addWidget(buttonPay, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        label_3 = new QLabel(replenishmentWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 0);"));

        gridLayout_2->addWidget(label_3, 2, 1, 1, 1);

        label_7 = new QLabel(replenishmentWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 1, 1, 1);


        gridLayout->addWidget(replenishmentWidget, 0, 1, 1, 1);

        cardHolderWidget = new QWidget(PlayerPayments);
        cardHolderWidget->setObjectName(QString::fromUtf8("cardHolderWidget"));
        sizePolicy1.setHeightForWidth(cardHolderWidget->sizePolicy().hasHeightForWidth());
        cardHolderWidget->setSizePolicy(sizePolicy1);
        cardHolderWidget->setStyleSheet(QString::fromUtf8("#cardHolderWidget\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(170, 85, 255, 255), stop:1 rgba(255, 85, 127, 255));\n"
"}"));
        gridLayout_4 = new QGridLayout(cardHolderWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_16 = new QLabel(cardHolderWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(60, 50));
        label_16->setStyleSheet(QString::fromUtf8("image: url(:/bank/resources/banks/ChipCard.png);"));
        label_16->setScaledContents(true);

        horizontalLayout_3->addWidget(label_16);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_17 = new QLabel(cardHolderWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(60, 50));
        label_17->setStyleSheet(QString::fromUtf8("image: url(:/bank/resources/banks/mastercard.png);"));
        label_17->setScaledContents(true);

        horizontalLayout_3->addWidget(label_17);


        gridLayout_4->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        lineEdit_6 = new QLineEdit(cardHolderWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy2);
        lineEdit_6->setMaximumSize(QSize(50, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        lineEdit_6->setFont(font4);
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_6->setMaxLength(4);
        lineEdit_6->setFrame(false);

        horizontalLayout->addWidget(lineEdit_6);

        label_8 = new QLabel(cardHolderWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Segoe UI"));
        font5.setPointSize(24);
        font5.setBold(true);
        font5.setWeight(75);
        label_8->setFont(font5);

        horizontalLayout->addWidget(label_8);

        lineEdit_7 = new QLineEdit(cardHolderWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        sizePolicy2.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy2);
        lineEdit_7->setMaximumSize(QSize(50, 16777215));
        lineEdit_7->setFont(font4);
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_7->setMaxLength(4);
        lineEdit_7->setFrame(false);

        horizontalLayout->addWidget(lineEdit_7);

        label_9 = new QLabel(cardHolderWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setFont(font5);

        horizontalLayout->addWidget(label_9);

        lineEdit_8 = new QLineEdit(cardHolderWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        sizePolicy2.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy2);
        lineEdit_8->setMaximumSize(QSize(50, 16777215));
        lineEdit_8->setFont(font4);
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_8->setMaxLength(4);
        lineEdit_8->setFrame(false);

        horizontalLayout->addWidget(lineEdit_8);

        label_10 = new QLabel(cardHolderWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setFont(font5);

        horizontalLayout->addWidget(label_10);

        lineEdit_9 = new QLineEdit(cardHolderWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        sizePolicy2.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy2);
        lineEdit_9->setMaximumSize(QSize(50, 16777215));
        lineEdit_9->setFont(font4);
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_9->setMaxLength(4);
        lineEdit_9->setFrame(false);

        horizontalLayout->addWidget(lineEdit_9);

        horizontalSpacer_6 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout_4->addLayout(horizontalLayout, 3, 0, 1, 2);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        lineEdit_2 = new QLineEdit(cardHolderWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setMaximumSize(QSize(140, 16777215));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Segoe UI"));
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        lineEdit_2->setFont(font6);
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_2->setFrame(false);

        gridLayout_9->addWidget(lineEdit_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(cardHolderWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        sizePolicy2.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy2);
        lineEdit_3->setMaximumSize(QSize(140, 16777215));
        lineEdit_3->setFont(font6);
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_3->setFrame(false);

        gridLayout_9->addWidget(lineEdit_3, 1, 1, 1, 1);

        label_13 = new QLabel(cardHolderWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font6);
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_9->addWidget(label_13, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_2, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_9, 5, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_12 = new QLabel(cardHolderWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(30, 16777215));
        label_12->setFont(font6);

        gridLayout_7->addWidget(label_12, 0, 4, 1, 1);

        lineEdit_5 = new QLineEdit(cardHolderWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        sizePolicy2.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy2);
        lineEdit_5->setMaximumSize(QSize(50, 16777215));
        lineEdit_5->setFont(font6);
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_5->setMaxLength(2);
        lineEdit_5->setFrame(false);
        lineEdit_5->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_5, 1, 0, 1, 1);

        label_11 = new QLabel(cardHolderWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(10, 0));
        label_11->setFont(font4);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_11, 1, 1, 1, 1);

        lineEdit_10 = new QLineEdit(cardHolderWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setMaximumSize(QSize(30, 16777215));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Segoe UI"));
        font7.setPointSize(10);
        lineEdit_10->setFont(font7);
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_10->setMaxLength(3);
        lineEdit_10->setFrame(false);
        lineEdit_10->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(lineEdit_10, 1, 4, 1, 1);

        lineEdit_4 = new QLineEdit(cardHolderWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        sizePolicy2.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy2);
        lineEdit_4->setMaximumSize(QSize(50, 16777215));
        lineEdit_4->setFont(font6);
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: white;\n"
"	color: black\n"
"}"));
        lineEdit_4->setMaxLength(2);
        lineEdit_4->setFrame(false);
        lineEdit_4->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lineEdit_4, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer, 1, 3, 1, 1);

        label_14 = new QLabel(cardHolderWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font6);
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_14->setWordWrap(false);

        gridLayout_7->addWidget(label_14, 0, 0, 1, 3);


        gridLayout_4->addLayout(gridLayout_7, 6, 0, 1, 1);


        gridLayout->addWidget(cardHolderWidget, 0, 0, 1, 1);

        otherPaymentMethodsWidget = new QWidget(PlayerPayments);
        otherPaymentMethodsWidget->setObjectName(QString::fromUtf8("otherPaymentMethodsWidget"));
        sizePolicy.setHeightForWidth(otherPaymentMethodsWidget->sizePolicy().hasHeightForWidth());
        otherPaymentMethodsWidget->setSizePolicy(sizePolicy);
        otherPaymentMethodsWidget->setStyleSheet(QString::fromUtf8("#otherPaymentMethodsWidget\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"}"));
        gridLayout_3 = new QGridLayout(otherPaymentMethodsWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        buttonSBP = new QPushButton(otherPaymentMethodsWidget);
        buttonSBP->setObjectName(QString::fromUtf8("buttonSBP"));
        buttonSBP->setFont(font6);
        buttonSBP->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	text-align: left;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/bank/resources/banks/sbp.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSBP->setIcon(icon);
        buttonSBP->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(buttonSBP, 1, 0, 1, 1);

        buttonYOOMoney = new QPushButton(otherPaymentMethodsWidget);
        buttonYOOMoney->setObjectName(QString::fromUtf8("buttonYOOMoney"));
        buttonYOOMoney->setFont(font6);
        buttonYOOMoney->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	text-align: left;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/bank/resources/banks/yoomoney.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonYOOMoney->setIcon(icon1);
        buttonYOOMoney->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(buttonYOOMoney, 2, 1, 1, 1);

        buttonVKPay = new QPushButton(otherPaymentMethodsWidget);
        buttonVKPay->setObjectName(QString::fromUtf8("buttonVKPay"));
        buttonVKPay->setFont(font6);
        buttonVKPay->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	text-align: left;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/bank/resources/banks/vkpay.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonVKPay->setIcon(icon2);
        buttonVKPay->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(buttonVKPay, 2, 0, 1, 1);

        buttonMTS = new QPushButton(otherPaymentMethodsWidget);
        buttonMTS->setObjectName(QString::fromUtf8("buttonMTS"));
        buttonMTS->setFont(font6);
        buttonMTS->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	text-align: left;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/bank/resources/banks/mtsbank.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMTS->setIcon(icon3);
        buttonMTS->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(buttonMTS, 3, 0, 1, 1);

        buttonSber = new QPushButton(otherPaymentMethodsWidget);
        buttonSber->setObjectName(QString::fromUtf8("buttonSber"));
        buttonSber->setFont(font6);
        buttonSber->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	text-align: left;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/bank/resources/banks/sberbank.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonSber->setIcon(icon4);
        buttonSber->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(buttonSber, 1, 1, 1, 1);

        buttonWebMoney = new QPushButton(otherPaymentMethodsWidget);
        buttonWebMoney->setObjectName(QString::fromUtf8("buttonWebMoney"));
        buttonWebMoney->setFont(font6);
        buttonWebMoney->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	text-align: left;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"	background-color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/bank/resources/banks/webmoney.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonWebMoney->setIcon(icon5);
        buttonWebMoney->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(buttonWebMoney, 3, 1, 1, 1);

        label_2 = new QLabel(otherPaymentMethodsWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 2);


        gridLayout->addWidget(otherPaymentMethodsWidget, 0, 2, 1, 1);

        searchWidget = new QWidget(PlayerPayments);
        searchWidget->setObjectName(QString::fromUtf8("searchWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(searchWidget->sizePolicy().hasHeightForWidth());
        searchWidget->setSizePolicy(sizePolicy3);
        searchWidget->setStyleSheet(QString::fromUtf8("#searchWidget\n"
"{\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"}"));
        verticalLayout = new QVBoxLayout(searchWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelHistoriPayments = new QLabel(searchWidget);
        labelHistoriPayments->setObjectName(QString::fromUtf8("labelHistoriPayments"));
        labelHistoriPayments->setFont(font2);

        verticalLayout->addWidget(labelHistoriPayments);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBox_Search = new QCheckBox(searchWidget);
        checkBox_Search->setObjectName(QString::fromUtf8("checkBox_Search"));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Segoe UI"));
        font8.setPointSize(14);
        checkBox_Search->setFont(font8);

        horizontalLayout_4->addWidget(checkBox_Search);

        checkBox_Sorting = new QCheckBox(searchWidget);
        checkBox_Sorting->setObjectName(QString::fromUtf8("checkBox_Sorting"));
        checkBox_Sorting->setFont(font8);

        horizontalLayout_4->addWidget(checkBox_Sorting);

        horizontalSpacer_11 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        refreshData = new QPushButton(searchWidget);
        refreshData->setObjectName(QString::fromUtf8("refreshData"));
        refreshData->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshData->setIcon(icon6);
        refreshData->setIconSize(QSize(24, 24));

        horizontalLayout_4->addWidget(refreshData);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(searchWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_9->addWidget(label);

        searchColumn = new QComboBox(searchWidget);
        searchColumn->setObjectName(QString::fromUtf8("searchColumn"));
        searchColumn->setFont(font2);

        horizontalLayout_9->addWidget(searchColumn);

        searchText = new QLineEdit(searchWidget);
        searchText->setObjectName(QString::fromUtf8("searchText"));
        searchText->setFont(font);

        horizontalLayout_9->addWidget(searchText);

        checkBox = new QCheckBox(searchWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        horizontalLayout_9->addWidget(checkBox);

        pushButton_search = new QPushButton(searchWidget);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_search->setIcon(icon7);
        pushButton_search->setIconSize(QSize(24, 24));

        horizontalLayout_9->addWidget(pushButton_search);

        clearSearch = new QPushButton(searchWidget);
        clearSearch->setObjectName(QString::fromUtf8("clearSearch"));
        clearSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/resources/clearSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearSearch->setIcon(icon8);
        clearSearch->setIconSize(QSize(24, 24));

        horizontalLayout_9->addWidget(clearSearch);

        horizontalSpacer_14 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        sorting = new QCheckBox(searchWidget);
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setFont(font);

        horizontalLayout_8->addWidget(sorting);

        label_19 = new QLabel(searchWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font);

        horizontalLayout_8->addWidget(label_19);

        sortingColumn = new QComboBox(searchWidget);
        sortingColumn->setObjectName(QString::fromUtf8("sortingColumn"));
        sortingColumn->setFont(font2);

        horizontalLayout_8->addWidget(sortingColumn);

        label_20 = new QLabel(searchWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setFont(font);

        horizontalLayout_8->addWidget(label_20);

        typeSorting = new QComboBox(searchWidget);
        typeSorting->addItem(QString());
        typeSorting->addItem(QString());
        typeSorting->setObjectName(QString::fromUtf8("typeSorting"));
        sizePolicy2.setHeightForWidth(typeSorting->sizePolicy().hasHeightForWidth());
        typeSorting->setSizePolicy(sizePolicy2);
        typeSorting->setFont(font4);

        horizontalLayout_8->addWidget(typeSorting);

        horizontalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_15 = new QLabel(searchWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setFont(font);

        horizontalLayout_2->addWidget(label_15);

        label_18 = new QLabel(searchWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setFont(font);

        horizontalLayout_2->addWidget(label_18);

        horizontalSpacer_8 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(searchWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setFont(font7);

        verticalLayout->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        label_4 = new QLabel(searchWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_6->addWidget(label_4);

        labelCurrentPage = new QLabel(searchWidget);
        labelCurrentPage->setObjectName(QString::fromUtf8("labelCurrentPage"));
        labelCurrentPage->setFont(font2);

        horizontalLayout_6->addWidget(labelCurrentPage);

        label_5 = new QLabel(searchWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        labelMaxPage = new QLabel(searchWidget);
        labelMaxPage->setObjectName(QString::fromUtf8("labelMaxPage"));
        labelMaxPage->setFont(font2);

        horizontalLayout_6->addWidget(labelMaxPage);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        prevButton = new QPushButton(searchWidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        QFont font9;
        font9.setFamily(QString::fromUtf8("Segoe UI"));
        font9.setPointSize(18);
        prevButton->setFont(font9);
        prevButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon9);
        prevButton->setIconSize(QSize(24, 24));

        horizontalLayout_10->addWidget(prevButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        label_6 = new QLabel(searchWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_10->addWidget(label_6);

        pageNumberToNavigate = new QLineEdit(searchWidget);
        pageNumberToNavigate->setObjectName(QString::fromUtf8("pageNumberToNavigate"));
        pageNumberToNavigate->setMaximumSize(QSize(50, 16777215));
        pageNumberToNavigate->setFont(font);

        horizontalLayout_10->addWidget(pageNumberToNavigate);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        nextButton = new QPushButton(searchWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setFont(font9);
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon10);
        nextButton->setIconSize(QSize(24, 24));

        horizontalLayout_10->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout_10);


        gridLayout->addWidget(searchWidget, 1, 0, 4, 4);


        retranslateUi(PlayerPayments);

        QMetaObject::connectSlotsByName(PlayerPayments);
    } // setupUi

    void retranslateUi(QWidget *PlayerPayments)
    {
        PlayerPayments->setWindowTitle(QApplication::translate("PlayerPayments", "Form", nullptr));
        labelInformation->setText(QApplication::translate("PlayerPayments", "\320\237\320\276\320\277\320\276\320\273\320\275\321\217\321\217 \321\201\320\262\320\276\320\271 \320\261\320\260\320\273\320\260\320\275\321\201, \320\222\321\213 \320\264\320\260\321\221\321\202\320\265 \321\201\320\276\320\263\320\273\320\260\321\201\320\270\320\265 \321\201 \320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\270\320\274 \321\201\320\276\320\263\320\273\320\260\321\210\320\265\320\275\320\270\320\265\320\274 \320\262 \320\276\321\202\320\275\320\260\321\210\320\265\320\275\320\270\320\270 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \320\222\320\260\321\210\320\270\321\205 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205 \320\262 \320\241\320\276\320\276\321\202\320\262\320\265\321\202\321\201\320\262\320\270\320\270 \321\201 \320\244\320\227 \342\204\226152 \"\320\236 \320\267\320\260\321\211\320\270\321"
                        "\202\320\265 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205\", \320\260 \321\202\320\260\320\272\320\266\320\265 \321\201\320\276\320\263\320\273\320\260\321\210\320\260\320\265\321\202\320\265\321\201\321\214 \321\201 \321\203\321\201\320\273\320\276\320\262\320\270\320\265\320\274 \320\277\321\203\320\261\320\273\320\270\321\207\320\275\320\276\320\271 \320\276\321\204\320\265\321\200\321\202\321\213", nullptr));
        buttonPay->setText(QApplication::translate("PlayerPayments", "\320\236\320\277\320\273\320\260\321\202\320\270\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("PlayerPayments", "\320\232\320\276\320\274\320\270\321\201\320\270\321\217 \320\261\320\260\320\275\320\272\320\260 0%", nullptr));
        label_7->setText(QApplication::translate("PlayerPayments", "\320\237\320\276\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\201\321\207\321\221\321\202", nullptr));
        label_17->setText(QString());
        lineEdit_6->setPlaceholderText(QApplication::translate("PlayerPayments", "0000", nullptr));
        label_8->setText(QApplication::translate("PlayerPayments", "-", nullptr));
        lineEdit_7->setPlaceholderText(QApplication::translate("PlayerPayments", "0000", nullptr));
        label_9->setText(QApplication::translate("PlayerPayments", "-", nullptr));
        lineEdit_8->setPlaceholderText(QApplication::translate("PlayerPayments", "0000", nullptr));
        label_10->setText(QApplication::translate("PlayerPayments", "-", nullptr));
        lineEdit_9->setPlaceholderText(QApplication::translate("PlayerPayments", "0000", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("PlayerPayments", "FIRSTNAME", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("PlayerPayments", "LASTNAME", nullptr));
        label_13->setText(QApplication::translate("PlayerPayments", "Card Holder", nullptr));
        label_12->setText(QApplication::translate("PlayerPayments", "CVC", nullptr));
        lineEdit_5->setPlaceholderText(QApplication::translate("PlayerPayments", "MM", nullptr));
        label_11->setText(QApplication::translate("PlayerPayments", "/", nullptr));
        lineEdit_10->setPlaceholderText(QApplication::translate("PlayerPayments", "***", nullptr));
        lineEdit_4->setInputMask(QString());
        lineEdit_4->setPlaceholderText(QApplication::translate("PlayerPayments", "YY", nullptr));
        label_14->setText(QApplication::translate("PlayerPayments", "Validity period", nullptr));
        buttonSBP->setText(QApplication::translate("PlayerPayments", "\320\241\320\221\320\237", nullptr));
        buttonYOOMoney->setText(QApplication::translate("PlayerPayments", "\320\256 Money", nullptr));
        buttonVKPay->setText(QApplication::translate("PlayerPayments", "VK Pay", nullptr));
        buttonMTS->setText(QApplication::translate("PlayerPayments", "\320\234\320\242\320\241 \320\221\320\260\320\275\320\272", nullptr));
        buttonSber->setText(QApplication::translate("PlayerPayments", "\320\241\320\261\320\265\321\200", nullptr));
        buttonWebMoney->setText(QApplication::translate("PlayerPayments", "WebMoney", nullptr));
        label_2->setText(QApplication::translate("PlayerPayments", "\320\224\321\200\321\203\320\263\320\270\320\265 \321\201\320\277\320\276\321\201\320\276\320\261\321\213 \320\276\320\277\320\273\320\260\321\202\321\213", nullptr));
        labelHistoriPayments->setText(QApplication::translate("PlayerPayments", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
        checkBox_Search->setText(QApplication::translate("PlayerPayments", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        checkBox_Sorting->setText(QApplication::translate("PlayerPayments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        refreshData->setText(QString());
        label->setText(QApplication::translate("PlayerPayments", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox->setText(QApplication::translate("PlayerPayments", "\320\242\320\276\321\207\320\275\320\276\320\265 \n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton_search->setText(QString());
        clearSearch->setText(QString());
        sorting->setText(QApplication::translate("PlayerPayments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_19->setText(QApplication::translate("PlayerPayments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:", nullptr));
        label_20->setText(QApplication::translate("PlayerPayments", "\320\277\320\276", nullptr));
        typeSorting->setItemText(0, QApplication::translate("PlayerPayments", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        typeSorting->setItemText(1, QApplication::translate("PlayerPayments", "\320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));

        label_15->setText(QApplication::translate("PlayerPayments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260:", nullptr));
        label_18->setText(QApplication::translate("PlayerPayments", "\320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        label_4->setText(QApplication::translate("PlayerPayments", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260:", nullptr));
        labelCurrentPage->setText(QApplication::translate("PlayerPayments", "0", nullptr));
        label_5->setText(QApplication::translate("PlayerPayments", "/", nullptr));
        labelMaxPage->setText(QApplication::translate("PlayerPayments", "????", nullptr));
        prevButton->setText(QString());
        label_6->setText(QApplication::translate("PlayerPayments", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\265 \342\204\226:", nullptr));
        nextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayerPayments: public Ui_PlayerPayments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERPAYMENTS_H
