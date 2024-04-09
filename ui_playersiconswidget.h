/********************************************************************************
** Form generated from reading UI file 'playersiconswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSICONSWIDGET_H
#define UI_PLAYERSICONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayersIconsWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *layoutIcon_1;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *layoutIcon_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *layoutIcon_3;
    QVBoxLayout *layoutIcon_4;
    QVBoxLayout *layoutIcon_5;
    QVBoxLayout *layoutIcon_6;
    QVBoxLayout *layoutIcon_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonTakeCard;
    QPushButton *buttonDoNotTakeCard;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *PlayersIconsWidget)
    {
        if (PlayersIconsWidget->objectName().isEmpty())
            PlayersIconsWidget->setObjectName(QString::fromUtf8("PlayersIconsWidget"));
        PlayersIconsWidget->resize(749, 380);
        PlayersIconsWidget->setStyleSheet(QString::fromUtf8("#PlayersIconsWidget{\n"
"	background-color: transparent;\n"
"}"));
        gridLayout = new QGridLayout(PlayersIconsWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 4, 1, 1);

        layoutIcon_1 = new QVBoxLayout();
        layoutIcon_1->setObjectName(QString::fromUtf8("layoutIcon_1"));

        gridLayout->addLayout(layoutIcon_1, 7, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 5, 1, 1);

        layoutIcon_2 = new QVBoxLayout();
        layoutIcon_2->setObjectName(QString::fromUtf8("layoutIcon_2"));

        gridLayout->addLayout(layoutIcon_2, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 5, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 1, 1, 1);

        layoutIcon_3 = new QVBoxLayout();
        layoutIcon_3->setObjectName(QString::fromUtf8("layoutIcon_3"));

        gridLayout->addLayout(layoutIcon_3, 3, 1, 1, 1);

        layoutIcon_4 = new QVBoxLayout();
        layoutIcon_4->setObjectName(QString::fromUtf8("layoutIcon_4"));

        gridLayout->addLayout(layoutIcon_4, 3, 3, 1, 1);

        layoutIcon_5 = new QVBoxLayout();
        layoutIcon_5->setObjectName(QString::fromUtf8("layoutIcon_5"));

        gridLayout->addLayout(layoutIcon_5, 3, 5, 1, 1);

        layoutIcon_6 = new QVBoxLayout();
        layoutIcon_6->setObjectName(QString::fromUtf8("layoutIcon_6"));

        gridLayout->addLayout(layoutIcon_6, 5, 5, 1, 1);

        layoutIcon_7 = new QVBoxLayout();
        layoutIcon_7->setObjectName(QString::fromUtf8("layoutIcon_7"));

        gridLayout->addLayout(layoutIcon_7, 7, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        buttonTakeCard = new QPushButton(PlayersIconsWidget);
        buttonTakeCard->setObjectName(QString::fromUtf8("buttonTakeCard"));

        horizontalLayout->addWidget(buttonTakeCard);

        buttonDoNotTakeCard = new QPushButton(PlayersIconsWidget);
        buttonDoNotTakeCard->setObjectName(QString::fromUtf8("buttonDoNotTakeCard"));

        horizontalLayout->addWidget(buttonDoNotTakeCard);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 7, 2, 1, 3);


        retranslateUi(PlayersIconsWidget);

        QMetaObject::connectSlotsByName(PlayersIconsWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayersIconsWidget)
    {
        PlayersIconsWidget->setWindowTitle(QApplication::translate("PlayersIconsWidget", "Form", nullptr));
        buttonTakeCard->setText(QApplication::translate("PlayersIconsWidget", "\320\222\320\267\321\217\321\202\321\214 \320\265\321\211\321\221", nullptr));
        buttonDoNotTakeCard->setText(QApplication::translate("PlayersIconsWidget", "\320\235\320\265 \320\261\321\200\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayersIconsWidget: public Ui_PlayersIconsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSICONSWIDGET_H
