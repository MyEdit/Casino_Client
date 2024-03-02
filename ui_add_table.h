/********************************************************************************
** Form generated from reading UI file 'add_table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_TABLE_H
#define UI_ADD_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_Table
{
public:

    void setupUi(QWidget *Add_Table)
    {
        if (Add_Table->objectName().isEmpty())
            Add_Table->setObjectName(QString::fromUtf8("Add_Table"));
        Add_Table->resize(400, 300);

        retranslateUi(Add_Table);

        QMetaObject::connectSlotsByName(Add_Table);
    } // setupUi

    void retranslateUi(QWidget *Add_Table)
    {
        Add_Table->setWindowTitle(QApplication::translate("Add_Table", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Add_Table: public Ui_Add_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_TABLE_H
