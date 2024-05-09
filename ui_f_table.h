/********************************************************************************
** Form generated from reading UI file 'f_table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_TABLE_H
#define UI_F_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_Table
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *F_Table)
    {
        if (F_Table->objectName().isEmpty())
            F_Table->setObjectName(QString::fromUtf8("F_Table"));
        F_Table->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_Table);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        retranslateUi(F_Table);

        QMetaObject::connectSlotsByName(F_Table);
    } // setupUi

    void retranslateUi(QDialog *F_Table)
    {
        F_Table->setWindowTitle(QApplication::translate("F_Table", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Table: public Ui_F_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_TABLE_H
