/********************************************************************************
** Form generated from reading UI file 'add_ban.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_BAN_H
#define UI_ADD_BAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_Ban
{
public:

    void setupUi(QWidget *Add_Ban)
    {
        if (Add_Ban->objectName().isEmpty())
            Add_Ban->setObjectName(QString::fromUtf8("Add_Ban"));
        Add_Ban->resize(400, 300);

        retranslateUi(Add_Ban);

        QMetaObject::connectSlotsByName(Add_Ban);
    } // setupUi

    void retranslateUi(QWidget *Add_Ban)
    {
        Add_Ban->setWindowTitle(QApplication::translate("Add_Ban", "\320\227\320\260\320\261\320\260\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Ban: public Ui_Add_Ban {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_BAN_H
