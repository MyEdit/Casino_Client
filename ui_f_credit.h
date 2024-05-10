/********************************************************************************
** Form generated from reading UI file 'f_credit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CREDIT_H
#define UI_F_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_Credit
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_Credit)
    {
        if (F_Credit->objectName().isEmpty())
            F_Credit->setObjectName(QString::fromUtf8("F_Credit"));
        F_Credit->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_Credit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_Credit);

        QMetaObject::connectSlotsByName(F_Credit);
    } // setupUi

    void retranslateUi(QDialog *F_Credit)
    {
        F_Credit->setWindowTitle(QApplication::translate("F_Credit", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\262\321\201\320\265\321\205 \320\272\321\200\320\265\320\264\320\270\321\202\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Credit: public Ui_F_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CREDIT_H
