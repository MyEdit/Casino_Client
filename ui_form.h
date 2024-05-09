/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelName;
    QLabel *name;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelMinBet;
    QLabel *minBet;
    QSpacerItem *horizontalSpacer;
    QLabel *labelBetStep;
    QLabel *betStep;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelMinBalance;
    QLabel *minBalance;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelPlayers;
    QLabel *currentNumPlayer;
    QLabel *labelSeparator;
    QLabel *maxNumPlayer;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(830, 150);
        Form->setMaximumSize(QSize(16777215, 150));
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelName = new QLabel(Form);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelName);

        name = new QLabel(Form);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        labelMinBet = new QLabel(Form);
        labelMinBet->setObjectName(QString::fromUtf8("labelMinBet"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        labelMinBet->setFont(font1);
        labelMinBet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelMinBet);

        minBet = new QLabel(Form);
        minBet->setObjectName(QString::fromUtf8("minBet"));
        minBet->setFont(font1);

        horizontalLayout_2->addWidget(minBet);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelBetStep = new QLabel(Form);
        labelBetStep->setObjectName(QString::fromUtf8("labelBetStep"));
        labelBetStep->setFont(font1);
        labelBetStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelBetStep);

        betStep = new QLabel(Form);
        betStep->setObjectName(QString::fromUtf8("betStep"));
        betStep->setFont(font1);

        horizontalLayout_2->addWidget(betStep);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        labelMinBalance = new QLabel(Form);
        labelMinBalance->setObjectName(QString::fromUtf8("labelMinBalance"));
        labelMinBalance->setFont(font1);
        labelMinBalance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelMinBalance);

        minBalance = new QLabel(Form);
        minBalance->setObjectName(QString::fromUtf8("minBalance"));
        minBalance->setFont(font1);

        horizontalLayout_2->addWidget(minBalance);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        labelPlayers = new QLabel(Form);
        labelPlayers->setObjectName(QString::fromUtf8("labelPlayers"));
        labelPlayers->setFont(font1);

        horizontalLayout_2->addWidget(labelPlayers);

        currentNumPlayer = new QLabel(Form);
        currentNumPlayer->setObjectName(QString::fromUtf8("currentNumPlayer"));
        currentNumPlayer->setFont(font1);

        horizontalLayout_2->addWidget(currentNumPlayer);

        labelSeparator = new QLabel(Form);
        labelSeparator->setObjectName(QString::fromUtf8("labelSeparator"));
        labelSeparator->setFont(font1);

        horizontalLayout_2->addWidget(labelSeparator);

        maxNumPlayer = new QLabel(Form);
        maxNumPlayer->setObjectName(QString::fromUtf8("maxNumPlayer"));
        maxNumPlayer->setFont(font1);

        horizontalLayout_2->addWidget(maxNumPlayer);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        labelName->setText(QApplication::translate("Form", "\320\230\320\263\321\200\320\260:", nullptr));
        name->setText(QApplication::translate("Form", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        labelMinBet->setText(QApplication::translate("Form", "\320\234\320\270\320\275. \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        minBet->setText(QApplication::translate("Form", "\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        labelBetStep->setText(QApplication::translate("Form", "\320\250\320\260\320\263 \320\277\320\276\320\262\321\213\321\210\320\265\320\275\321\217:", nullptr));
        betStep->setText(QApplication::translate("Form", "\321\210\320\260\320\263", nullptr));
        labelMinBalance->setText(QApplication::translate("Form", "\320\234\320\270\320\275. \320\261\320\260\320\273\320\260\320\275\321\201:", nullptr));
        minBalance->setText(QApplication::translate("Form", "\320\261\320\260\320\273\320\260\320\275\321\201", nullptr));
        labelPlayers->setText(QApplication::translate("Form", "\320\230\320\263\321\200\320\276\320\272\320\276\320\262:", nullptr));
        currentNumPlayer->setText(QApplication::translate("Form", "\321\202\320\265\320\272\321\203\321\211\320\265\320\265", nullptr));
        labelSeparator->setText(QApplication::translate("Form", "/", nullptr));
        maxNumPlayer->setText(QApplication::translate("Form", "\320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
