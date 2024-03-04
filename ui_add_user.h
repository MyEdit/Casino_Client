/********************************************************************************
** Form generated from reading UI file 'add_user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_USER_H
#define UI_ADD_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_User
{
public:

    void setupUi(QWidget *Add_User)
    {
        if (Add_User->objectName().isEmpty())
            Add_User->setObjectName(QString::fromUtf8("Add_User"));
        Add_User->resize(400, 300);

        retranslateUi(Add_User);

        QMetaObject::connectSlotsByName(Add_User);
    } // setupUi

    void retranslateUi(QWidget *Add_User)
    {
        Add_User->setWindowTitle(QApplication::translate("Add_User", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_User: public Ui_Add_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_USER_H
