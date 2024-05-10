/********************************************************************************
** Form generated from reading UI file 'f_playercredit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_PLAYERCREDIT_H
#define UI_F_PLAYERCREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_PlayerCredit
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_PlayerCredit)
    {
        if (F_PlayerCredit->objectName().isEmpty())
            F_PlayerCredit->setObjectName(QString::fromUtf8("F_PlayerCredit"));
        F_PlayerCredit->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_PlayerCredit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_PlayerCredit);

        QMetaObject::connectSlotsByName(F_PlayerCredit);
    } // setupUi

    void retranslateUi(QDialog *F_PlayerCredit)
    {
        F_PlayerCredit->setWindowTitle(QApplication::translate("F_PlayerCredit", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\272\321\200\320\265\320\264\320\270\321\202\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_PlayerCredit: public Ui_F_PlayerCredit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_PLAYERCREDIT_H
