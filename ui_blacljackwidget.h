/********************************************************************************
** Form generated from reading UI file 'blacljackwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACLJACKWIDGET_H
#define UI_BLACLJACKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlaclJackWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonTakeCard;
    QPushButton *buttonDoNotTakeCard;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BlaclJackWidget)
    {
        if (BlaclJackWidget->objectName().isEmpty())
            BlaclJackWidget->setObjectName(QString::fromUtf8("BlaclJackWidget"));
        BlaclJackWidget->setEnabled(true);
        BlaclJackWidget->resize(800, 528);
        BlaclJackWidget->setMinimumSize(QSize(800, 0));
        gridLayout = new QGridLayout(BlaclJackWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonTakeCard = new QPushButton(BlaclJackWidget);
        buttonTakeCard->setObjectName(QString::fromUtf8("buttonTakeCard"));

        horizontalLayout_2->addWidget(buttonTakeCard);

        buttonDoNotTakeCard = new QPushButton(BlaclJackWidget);
        buttonDoNotTakeCard->setObjectName(QString::fromUtf8("buttonDoNotTakeCard"));

        horizontalLayout_2->addWidget(buttonDoNotTakeCard);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);


        retranslateUi(BlaclJackWidget);

        QMetaObject::connectSlotsByName(BlaclJackWidget);
    } // setupUi

    void retranslateUi(QWidget *BlaclJackWidget)
    {
        BlaclJackWidget->setWindowTitle(QApplication::translate("BlaclJackWidget", "Form", nullptr));
        buttonTakeCard->setText(QApplication::translate("BlaclJackWidget", "\320\222\320\267\321\217\321\202\321\214 \320\272\320\260\321\200\321\202\321\203", nullptr));
        buttonDoNotTakeCard->setText(QApplication::translate("BlaclJackWidget", "\320\245\320\262\320\260\321\202\320\270\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlaclJackWidget: public Ui_BlaclJackWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACLJACKWIDGET_H
