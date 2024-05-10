/********************************************************************************
** Form generated from reading UI file 'f_payment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_PAYMENT_H
#define UI_F_PAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_Payment
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_Payment)
    {
        if (F_Payment->objectName().isEmpty())
            F_Payment->setObjectName(QString::fromUtf8("F_Payment"));
        F_Payment->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_Payment);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_Payment);

        QMetaObject::connectSlotsByName(F_Payment);
    } // setupUi

    void retranslateUi(QDialog *F_Payment)
    {
        F_Payment->setWindowTitle(QApplication::translate("F_Payment", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\262\321\201\320\265\321\205 \320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Payment: public Ui_F_Payment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_PAYMENT_H
