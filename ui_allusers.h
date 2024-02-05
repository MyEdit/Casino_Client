/********************************************************************************
** Form generated from reading UI file 'allusers.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLUSERS_H
#define UI_ALLUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllUsers
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *AllUsers)
    {
        if (AllUsers->objectName().isEmpty())
            AllUsers->setObjectName(QString::fromUtf8("AllUsers"));
        AllUsers->resize(400, 300);
        gridLayout = new QGridLayout(AllUsers);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(AllUsers);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(AllUsers);

        QMetaObject::connectSlotsByName(AllUsers);
    } // setupUi

    void retranslateUi(QWidget *AllUsers)
    {
        AllUsers->setWindowTitle(QApplication::translate("AllUsers", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllUsers: public Ui_AllUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLUSERS_H
