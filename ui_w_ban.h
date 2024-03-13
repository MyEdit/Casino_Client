/********************************************************************************
** Form generated from reading UI file 'w_ban.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_W_BAN_H
#define UI_W_BAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_Ban
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *name;
    QLabel *labelName;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonReset;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonSave;
    QLabel *labelReason;
    QTextEdit *InputReason;

    void setupUi(QWidget *W_Ban)
    {
        if (W_Ban->objectName().isEmpty())
            W_Ban->setObjectName(QString::fromUtf8("W_Ban"));
        W_Ban->resize(398, 280);
        gridLayout_2 = new QGridLayout(W_Ban);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        name = new QLabel(W_Ban);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);

        gridLayout->addWidget(name, 0, 1, 1, 1);

        labelName = new QLabel(W_Ban);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy);
        labelName->setFont(font);
        labelName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelName, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        buttonReset = new QPushButton(W_Ban);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        buttonReset->setFont(font1);
        buttonReset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));

        horizontalLayout_4->addWidget(buttonReset);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        buttonSave = new QPushButton(W_Ban);
        buttonSave->setObjectName(QString::fromUtf8("buttonSave"));
        buttonSave->setFont(font1);
        buttonSave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));

        horizontalLayout_4->addWidget(buttonSave);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 2);

        labelReason = new QLabel(W_Ban);
        labelReason->setObjectName(QString::fromUtf8("labelReason"));
        sizePolicy.setHeightForWidth(labelReason->sizePolicy().hasHeightForWidth());
        labelReason->setSizePolicy(sizePolicy);
        labelReason->setFont(font);
        labelReason->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(labelReason, 1, 0, 1, 1);

        InputReason = new QTextEdit(W_Ban);
        InputReason->setObjectName(QString::fromUtf8("InputReason"));
        InputReason->setFont(font1);

        gridLayout->addWidget(InputReason, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(W_Ban);

        QMetaObject::connectSlotsByName(W_Ban);
    } // setupUi

    void retranslateUi(QWidget *W_Ban)
    {
        W_Ban->setWindowTitle(QApplication::translate("W_Ban", "\320\227\320\260\320\261\320\260\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        name->setText(QApplication::translate("W_Ban", "...", nullptr));
        labelName->setText(QApplication::translate("W_Ban", "\320\244\320\230\320\236:", nullptr));
        buttonReset->setText(QApplication::translate("W_Ban", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        buttonSave->setText(QApplication::translate("W_Ban", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        labelReason->setText(QApplication::translate("W_Ban", "\320\237\321\200\320\270\321\207\320\270\320\275\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_Ban: public Ui_W_Ban {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_W_BAN_H
