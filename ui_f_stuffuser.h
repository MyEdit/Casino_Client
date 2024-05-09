/********************************************************************************
** Form generated from reading UI file 'f_stuffuser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_STUFFUSER_H
#define UI_F_STUFFUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_StuffUser
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_StuffUser)
    {
        if (F_StuffUser->objectName().isEmpty())
            F_StuffUser->setObjectName(QString::fromUtf8("F_StuffUser"));
        F_StuffUser->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_StuffUser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_StuffUser);

        QMetaObject::connectSlotsByName(F_StuffUser);
    } // setupUi

    void retranslateUi(QDialog *F_StuffUser)
    {
        F_StuffUser->setWindowTitle(QApplication::translate("F_StuffUser", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_StuffUser: public Ui_F_StuffUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_STUFFUSER_H
