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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayersIconsWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QLabel *label_5;

    void setupUi(QWidget *PlayersIconsWidget)
    {
        if (PlayersIconsWidget->objectName().isEmpty())
            PlayersIconsWidget->setObjectName(QString::fromUtf8("PlayersIconsWidget"));
        PlayersIconsWidget->resize(855, 550);
        PlayersIconsWidget->setStyleSheet(QString::fromUtf8("#PlayersIconsWidget{\n"
"	background-color: transparent;\n"
"}"));
        gridLayout = new QGridLayout(PlayersIconsWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(PlayersIconsWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(100, 100));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(PlayersIconsWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(100, 100));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        label_7 = new QLabel(PlayersIconsWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(100, 100));
        label_7->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_3 = new QLabel(PlayersIconsWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(100, 100));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        verticalLayout_2->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        label_6 = new QLabel(PlayersIconsWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(100, 100));
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        verticalLayout_3->addWidget(label_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout->addLayout(verticalLayout_3, 1, 2, 1, 1);

        label = new QLabel(PlayersIconsWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(100, 100));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_5 = new QLabel(PlayersIconsWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(100, 100));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	border-image: url(:/InterfaceEements/resources/Player.png);\n"
"}"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);


        retranslateUi(PlayersIconsWidget);

        QMetaObject::connectSlotsByName(PlayersIconsWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayersIconsWidget)
    {
        PlayersIconsWidget->setWindowTitle(QApplication::translate("PlayersIconsWidget", "Form", nullptr));
        label_2->setText(QString());
        label_4->setText(QString());
        label_7->setText(QString());
        label_3->setText(QString());
        label_6->setText(QString());
        label->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlayersIconsWidget: public Ui_PlayersIconsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSICONSWIDGET_H
