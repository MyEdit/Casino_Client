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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QLabel *labelMinBalance;
    QSpacerItem *horizontalSpacer;
    QLabel *betStep;
    QLabel *minBalance;
    QLabel *minBet;
    QLabel *labelBetStep;
    QLabel *labelMinBet;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelName;
    QLabel *name;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(469, 138);
        Form->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelMinBalance = new QLabel(Form);
        labelMinBalance->setObjectName(QString::fromUtf8("labelMinBalance"));
        labelMinBalance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelMinBalance, 2, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        betStep = new QLabel(Form);
        betStep->setObjectName(QString::fromUtf8("betStep"));

        gridLayout->addWidget(betStep, 2, 4, 1, 1);

        minBalance = new QLabel(Form);
        minBalance->setObjectName(QString::fromUtf8("minBalance"));

        gridLayout->addWidget(minBalance, 2, 7, 1, 1);

        minBet = new QLabel(Form);
        minBet->setObjectName(QString::fromUtf8("minBet"));

        gridLayout->addWidget(minBet, 2, 1, 1, 1);

        labelBetStep = new QLabel(Form);
        labelBetStep->setObjectName(QString::fromUtf8("labelBetStep"));
        labelBetStep->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelBetStep, 2, 3, 1, 1);

        labelMinBet = new QLabel(Form);
        labelMinBet->setObjectName(QString::fromUtf8("labelMinBet"));
        labelMinBet->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelMinBet, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelName = new QLabel(Form);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelName);

        name = new QLabel(Form);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout->addWidget(name);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 8);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        labelMinBalance->setText(QApplication::translate("Form", "\320\234\320\270\320\275. \320\261\320\260\320\273\320\260\320\275\321\201:", nullptr));
        betStep->setText(QApplication::translate("Form", "\321\210\320\260\320\263", nullptr));
        minBalance->setText(QApplication::translate("Form", "\320\261\320\260\320\273\320\260\320\275\321\201", nullptr));
        minBet->setText(QApplication::translate("Form", "\321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        labelBetStep->setText(QApplication::translate("Form", "\320\250\320\260\320\263 \320\277\320\276\320\262\321\213\321\210\320\265\320\275\321\217:", nullptr));
        labelMinBet->setText(QApplication::translate("Form", "\320\234\320\270\320\275. \321\201\321\202\320\260\320\262\320\272\320\260:", nullptr));
        labelName->setText(QApplication::translate("Form", "\320\230\320\263\321\200\320\260:", nullptr));
        name->setText(QApplication::translate("Form", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
