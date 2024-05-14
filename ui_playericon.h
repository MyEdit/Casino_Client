/********************************************************************************
** Form generated from reading UI file 'playericon.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERICON_H
#define UI_PLAYERICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerIcon
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *playerIcon;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *playerName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCard;
    QLabel *countCard;
    QHBoxLayout *horizontalLayout;
    QLabel *labelScore;
    QLabel *score;

    void setupUi(QWidget *PlayerIcon)
    {
        if (PlayerIcon->objectName().isEmpty())
            PlayerIcon->setObjectName(QString::fromUtf8("PlayerIcon"));
        PlayerIcon->resize(140, 196);
        PlayerIcon->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_4 = new QVBoxLayout(PlayerIcon);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        playerIcon = new QLabel(PlayerIcon);
        playerIcon->setObjectName(QString::fromUtf8("playerIcon"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playerIcon->sizePolicy().hasHeightForWidth());
        playerIcon->setSizePolicy(sizePolicy);
        playerIcon->setMinimumSize(QSize(100, 100));
        playerIcon->setMaximumSize(QSize(100, 100));
        playerIcon->setStyleSheet(QString::fromUtf8(""));
        playerIcon->setScaledContents(false);
        playerIcon->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(playerIcon);

        widget = new QWidget(PlayerIcon);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("#widget {\n"
"    background-color: rgb(255, 255, 255);\n"
"    border: 1px solid black; \n"
"	border-radius: 5px;\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        playerName = new QLabel(widget);
        playerName->setObjectName(QString::fromUtf8("playerName"));
        playerName->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        playerName->setFont(font);
        playerName->setAlignment(Qt::AlignCenter);
        playerName->setWordWrap(true);

        verticalLayout_2->addWidget(playerName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelCard = new QLabel(widget);
        labelCard->setObjectName(QString::fromUtf8("labelCard"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        labelCard->setFont(font1);
        labelCard->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelCard);

        countCard = new QLabel(widget);
        countCard->setObjectName(QString::fromUtf8("countCard"));
        countCard->setFont(font1);

        horizontalLayout_2->addWidget(countCard);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelScore = new QLabel(widget);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        labelScore->setFont(font1);
        labelScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelScore);

        score = new QLabel(widget);
        score->setObjectName(QString::fromUtf8("score"));
        score->setFont(font);

        horizontalLayout->addWidget(score);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(widget);


        retranslateUi(PlayerIcon);

        QMetaObject::connectSlotsByName(PlayerIcon);
    } // setupUi

    void retranslateUi(QWidget *PlayerIcon)
    {
        PlayerIcon->setWindowTitle(QApplication::translate("PlayerIcon", "Form", nullptr));
        playerIcon->setText(QString());
        playerName->setText(QApplication::translate("PlayerIcon", "\320\230\320\274\321\217", nullptr));
        labelCard->setText(QApplication::translate("PlayerIcon", "\320\232\320\260\321\200\321\202:", nullptr));
        countCard->setText(QApplication::translate("PlayerIcon", "0", nullptr));
        labelScore->setText(QApplication::translate("PlayerIcon", "\320\241\321\207\321\221\321\202:", nullptr));
        score->setText(QApplication::translate("PlayerIcon", "????", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerIcon: public Ui_PlayerIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERICON_H
