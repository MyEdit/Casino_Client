/********************************************************************************
** Form generated from reading UI file 'gametable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMETABLE_H
#define UI_GAMETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameTable
{
public:
    QVBoxLayout *verticalLayoutMain;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayoutContent;

    void setupUi(QWidget *GameTable)
    {
        if (GameTable->objectName().isEmpty())
            GameTable->setObjectName(QString::fromUtf8("GameTable"));
        GameTable->resize(535, 402);
        verticalLayoutMain = new QVBoxLayout(GameTable);
        verticalLayoutMain->setObjectName(QString::fromUtf8("verticalLayoutMain"));
        scrollArea = new QScrollArea(GameTable);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 515, 382));
        verticalLayoutContent = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayoutContent->setObjectName(QString::fromUtf8("verticalLayoutContent"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayoutMain->addWidget(scrollArea);


        retranslateUi(GameTable);

        QMetaObject::connectSlotsByName(GameTable);
    } // setupUi

    void retranslateUi(QWidget *GameTable)
    {
        GameTable->setWindowTitle(QApplication::translate("GameTable", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameTable: public Ui_GameTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMETABLE_H
