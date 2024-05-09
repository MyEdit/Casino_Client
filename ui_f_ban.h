/********************************************************************************
** Form generated from reading UI file 'f_ban.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_BAN_H
#define UI_F_BAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_Ban
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_Ban)
    {
        if (F_Ban->objectName().isEmpty())
            F_Ban->setObjectName(QString::fromUtf8("F_Ban"));
        F_Ban->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_Ban);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_Ban);

        QMetaObject::connectSlotsByName(F_Ban);
    } // setupUi

    void retranslateUi(QDialog *F_Ban)
    {
        F_Ban->setWindowTitle(QApplication::translate("F_Ban", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Ban: public Ui_F_Ban {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_BAN_H
