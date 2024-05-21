/********************************************************************************
** Form generated from reading UI file 'blackjackbackground.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACKJACKBACKGROUND_H
#define UI_BLACKJACKBACKGROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlackJackBackground
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *labelDeck;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelCard_1;
    QLabel *labelCard_2;
    QLabel *labelCard_3;
    QLabel *labelCard_4;
    QLabel *labelCard_5;
    QLabel *labelCard_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *BlackJackBackground)
    {
        if (BlackJackBackground->objectName().isEmpty())
            BlackJackBackground->setObjectName(QString::fromUtf8("BlackJackBackground"));
        BlackJackBackground->resize(716, 484);
        BlackJackBackground->setMinimumSize(QSize(650, 400));
        BlackJackBackground->setAutoFillBackground(false);
        BlackJackBackground->setStyleSheet(QString::fromUtf8("#BlackJackBackground{\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(BlackJackBackground);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelDeck = new QLabel(BlackJackBackground);
        labelDeck->setObjectName(QString::fromUtf8("labelDeck"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelDeck->sizePolicy().hasHeightForWidth());
        labelDeck->setSizePolicy(sizePolicy);
        labelDeck->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"	border-image: url(:/Games/BlackDjack/assets/\320\232\320\276\320\273\320\276\320\264\320\260.png);\n"
"}"));

        horizontalLayout_2->addWidget(labelDeck);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        labelCard_1 = new QLabel(BlackJackBackground);
        labelCard_1->setObjectName(QString::fromUtf8("labelCard_1"));
        labelCard_1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));

        horizontalLayout_2->addWidget(labelCard_1);

        labelCard_2 = new QLabel(BlackJackBackground);
        labelCard_2->setObjectName(QString::fromUtf8("labelCard_2"));
        labelCard_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));

        horizontalLayout_2->addWidget(labelCard_2);

        labelCard_3 = new QLabel(BlackJackBackground);
        labelCard_3->setObjectName(QString::fromUtf8("labelCard_3"));
        labelCard_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));

        horizontalLayout_2->addWidget(labelCard_3);

        labelCard_4 = new QLabel(BlackJackBackground);
        labelCard_4->setObjectName(QString::fromUtf8("labelCard_4"));
        labelCard_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));

        horizontalLayout_2->addWidget(labelCard_4);

        labelCard_5 = new QLabel(BlackJackBackground);
        labelCard_5->setObjectName(QString::fromUtf8("labelCard_5"));
        labelCard_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));

        horizontalLayout_2->addWidget(labelCard_5);

        labelCard_6 = new QLabel(BlackJackBackground);
        labelCard_6->setObjectName(QString::fromUtf8("labelCard_6"));
        labelCard_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border: 2px solid  rgb(255, 255, 255);\n"
"	border-radius: 10px;\n"
"}"));

        horizontalLayout_2->addWidget(labelCard_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(BlackJackBackground);

        QMetaObject::connectSlotsByName(BlackJackBackground);
    } // setupUi

    void retranslateUi(QWidget *BlackJackBackground)
    {
        BlackJackBackground->setWindowTitle(QApplication::translate("BlackJackBackground", "Form", nullptr));
        labelDeck->setText(QString());
        labelCard_1->setText(QString());
        labelCard_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BlackJackBackground: public Ui_BlackJackBackground {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACKJACKBACKGROUND_H
