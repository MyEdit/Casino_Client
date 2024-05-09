/********************************************************************************
** Form generated from reading UI file 'f_user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_USER_H
#define UI_F_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_F_User
{
public:

    void setupUi(QDialog *F_User)
    {
        if (F_User->objectName().isEmpty())
            F_User->setObjectName(QString::fromUtf8("F_User"));
        F_User->resize(400, 300);

        retranslateUi(F_User);

        QMetaObject::connectSlotsByName(F_User);
    } // setupUi

    void retranslateUi(QDialog *F_User)
    {
        F_User->setWindowTitle(QApplication::translate("F_User", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_User: public Ui_F_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_USER_H
