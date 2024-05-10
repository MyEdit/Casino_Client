/********************************************************************************
** Form generated from reading UI file 'f_playerpayment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_PLAYERPAYMENT_H
#define UI_F_PLAYERPAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_PlayerPayment
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_PlayerPayment)
    {
        if (F_PlayerPayment->objectName().isEmpty())
            F_PlayerPayment->setObjectName(QString::fromUtf8("F_PlayerPayment"));
        F_PlayerPayment->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_PlayerPayment);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_PlayerPayment);

        QMetaObject::connectSlotsByName(F_PlayerPayment);
    } // setupUi

    void retranslateUi(QDialog *F_PlayerPayment)
    {
        F_PlayerPayment->setWindowTitle(QApplication::translate("F_PlayerPayment", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_PlayerPayment: public Ui_F_PlayerPayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_PLAYERPAYMENT_H
