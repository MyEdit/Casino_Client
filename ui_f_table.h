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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_F_Table
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *reset;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *applyFilter;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *F_Table)
    {
        if (F_Table->objectName().isEmpty())
            F_Table->setObjectName(QString::fromUtf8("F_Table"));
        F_Table->resize(400, 300);
        verticalLayout = new QVBoxLayout(F_Table);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        reset = new QPushButton(F_Table);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        applyFilter = new QPushButton(F_Table);
        applyFilter->setObjectName(QString::fromUtf8("applyFilter"));

        horizontalLayout->addWidget(applyFilter);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(F_Table);

        QMetaObject::connectSlotsByName(F_Table);
    } // setupUi

    void retranslateUi(QDialog *F_Table)
    {
        F_Table->setWindowTitle(QApplication::translate("F_Table", "\320\244\320\270\320\273\321\214\321\202\321\200 \321\201\321\202\320\276\320\273\320\276\320\262", nullptr));
        reset->setText(QApplication::translate("F_Table", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        applyFilter->setText(QApplication::translate("F_Table", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class F_Table: public Ui_F_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_TABLE_H
