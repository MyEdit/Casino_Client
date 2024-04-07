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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlaclJackWidget
{
public:
    QGridLayout *gridLayout;

    void setupUi(QWidget *BlaclJackWidget)
    {
        if (BlaclJackWidget->objectName().isEmpty())
            BlaclJackWidget->setObjectName(QString::fromUtf8("BlaclJackWidget"));
        BlaclJackWidget->setEnabled(true);
        BlaclJackWidget->resize(800, 528);
        BlaclJackWidget->setMinimumSize(QSize(800, 0));
        gridLayout = new QGridLayout(BlaclJackWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        retranslateUi(BlaclJackWidget);

        QMetaObject::connectSlotsByName(BlaclJackWidget);
    } // setupUi

    void retranslateUi(QWidget *BlaclJackWidget)
    {
        BlaclJackWidget->setWindowTitle(QApplication::translate("BlaclJackWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BlaclJackWidget: public Ui_BlaclJackWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACLJACKWIDGET_H
