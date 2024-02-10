/********************************************************************************
** Form generated from reading UI file 'existingtables.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTINGTABLES_H
#define UI_EXISTINGTABLES_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExistingTables
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QComboBox *searchColumn_2;
    QLineEdit *searchText_2;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_search_2;
    QPushButton *clearSearch_2;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QComboBox *sortingColumn_2;
    QLabel *label_10;
    QComboBox *typeSorting_2;
    QCheckBox *sorting_2;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *moreDetailed_2;
    QPushButton *pushButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_5;
    QLabel *labelCurrentPage_2;
    QLabel *label_7;
    QLabel *labelMaxPage_2;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *prevButton_2;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_12;
    QLineEdit *pageNumberToNavigate_2;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *nextButton_2;
    QLabel *status;

    void setupUi(QWidget *ExistingTables)
    {
        if (ExistingTables->objectName().isEmpty())
            ExistingTables->setObjectName(QString::fromUtf8("ExistingTables"));
        ExistingTables->resize(1184, 768);
        verticalLayout = new QVBoxLayout(ExistingTables);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_11 = new QLabel(ExistingTables);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        label_11->setFont(font);

        horizontalLayout_9->addWidget(label_11);

        searchColumn_2 = new QComboBox(ExistingTables);
        searchColumn_2->setObjectName(QString::fromUtf8("searchColumn_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        searchColumn_2->setFont(font1);

        horizontalLayout_9->addWidget(searchColumn_2);

        searchText_2 = new QLineEdit(ExistingTables);
        searchText_2->setObjectName(QString::fromUtf8("searchText_2"));
        searchText_2->setFont(font);

        horizontalLayout_9->addWidget(searchText_2);

        checkBox_2 = new QCheckBox(ExistingTables);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setFont(font);

        horizontalLayout_9->addWidget(checkBox_2);

        pushButton_search_2 = new QPushButton(ExistingTables);
        pushButton_search_2->setObjectName(QString::fromUtf8("pushButton_search_2"));
        pushButton_search_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_search_2->setIcon(icon);
        pushButton_search_2->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(pushButton_search_2);

        clearSearch_2 = new QPushButton(ExistingTables);
        clearSearch_2->setObjectName(QString::fromUtf8("clearSearch_2"));
        clearSearch_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resources/clearSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearSearch_2->setIcon(icon1);
        clearSearch_2->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(clearSearch_2);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(ExistingTables);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        horizontalLayout_8->addWidget(label_9);

        sortingColumn_2 = new QComboBox(ExistingTables);
        sortingColumn_2->setObjectName(QString::fromUtf8("sortingColumn_2"));
        sortingColumn_2->setFont(font1);

        horizontalLayout_8->addWidget(sortingColumn_2);

        label_10 = new QLabel(ExistingTables);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font);

        horizontalLayout_8->addWidget(label_10);

        typeSorting_2 = new QComboBox(ExistingTables);
        typeSorting_2->addItem(QString());
        typeSorting_2->addItem(QString());
        typeSorting_2->setObjectName(QString::fromUtf8("typeSorting_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(typeSorting_2->sizePolicy().hasHeightForWidth());
        typeSorting_2->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        typeSorting_2->setFont(font2);

        horizontalLayout_8->addWidget(typeSorting_2);

        sorting_2 = new QCheckBox(ExistingTables);
        sorting_2->setObjectName(QString::fromUtf8("sorting_2"));
        sorting_2->setFont(font);

        horizontalLayout_8->addWidget(sorting_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        moreDetailed_2 = new QPushButton(ExistingTables);
        moreDetailed_2->setObjectName(QString::fromUtf8("moreDetailed_2"));
        moreDetailed_2->setFont(font2);
        moreDetailed_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
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

        horizontalLayout_8->addWidget(moreDetailed_2);

        pushButton = new QPushButton(ExistingTables);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 10px;\n"
"    padding: 5px 15px;\n"
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

        horizontalLayout_8->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_8);

        tableView = new QTableView(ExistingTables);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(10);
        tableView->setFont(font3);

        verticalLayout->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        label_5 = new QLabel(ExistingTables);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        labelCurrentPage_2 = new QLabel(ExistingTables);
        labelCurrentPage_2->setObjectName(QString::fromUtf8("labelCurrentPage_2"));
        labelCurrentPage_2->setFont(font1);

        horizontalLayout_6->addWidget(labelCurrentPage_2);

        label_7 = new QLabel(ExistingTables);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        horizontalLayout_6->addWidget(label_7);

        labelMaxPage_2 = new QLabel(ExistingTables);
        labelMaxPage_2->setObjectName(QString::fromUtf8("labelMaxPage_2"));
        labelMaxPage_2->setFont(font1);

        horizontalLayout_6->addWidget(labelMaxPage_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        prevButton_2 = new QPushButton(ExistingTables);
        prevButton_2->setObjectName(QString::fromUtf8("prevButton_2"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(18);
        prevButton_2->setFont(font4);
        prevButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; /* \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
"	padding-bottom: 3px;\n"
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

        horizontalLayout_10->addWidget(prevButton_2);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        label_12 = new QLabel(ExistingTables);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        horizontalLayout_10->addWidget(label_12);

        pageNumberToNavigate_2 = new QLineEdit(ExistingTables);
        pageNumberToNavigate_2->setObjectName(QString::fromUtf8("pageNumberToNavigate_2"));
        pageNumberToNavigate_2->setMaximumSize(QSize(50, 16777215));
        pageNumberToNavigate_2->setFont(font);

        horizontalLayout_10->addWidget(pageNumberToNavigate_2);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        nextButton_2 = new QPushButton(ExistingTables);
        nextButton_2->setObjectName(QString::fromUtf8("nextButton_2"));
        nextButton_2->setFont(font4);
        nextButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; /* \320\264\320\276\320\261\320\260\320\262\320\273\321\217\320\265\320\274 \320\276\320\261\320\262\320\276\320\264\320\272\321\203 */\n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
"	padding-bottom: 3px;\n"
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

        horizontalLayout_10->addWidget(nextButton_2);


        verticalLayout->addLayout(horizontalLayout_10);

        status = new QLabel(ExistingTables);
        status->setObjectName(QString::fromUtf8("status"));

        verticalLayout->addWidget(status);


        retranslateUi(ExistingTables);

        QMetaObject::connectSlotsByName(ExistingTables);
    } // setupUi

    void retranslateUi(QWidget *ExistingTables)
    {
        ExistingTables->setWindowTitle(QApplication::translate("ExistingTables", "Form", nullptr));
        label_11->setText(QApplication::translate("ExistingTables", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox_2->setText(QApplication::translate("ExistingTables", "\320\242\320\276\321\207\320\275\320\276\320\265 \n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton_search_2->setText(QString());
        clearSearch_2->setText(QString());
        label_9->setText(QApplication::translate("ExistingTables", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:", nullptr));
        label_10->setText(QApplication::translate("ExistingTables", "\320\277\320\276", nullptr));
        typeSorting_2->setItemText(0, QApplication::translate("ExistingTables", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        typeSorting_2->setItemText(1, QApplication::translate("ExistingTables", "\320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));

        sorting_2->setText(QApplication::translate("ExistingTables", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        moreDetailed_2->setText(QApplication::translate("ExistingTables", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        pushButton->setText(QApplication::translate("ExistingTables", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_5->setText(QApplication::translate("ExistingTables", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260:", nullptr));
        labelCurrentPage_2->setText(QApplication::translate("ExistingTables", "1", nullptr));
        label_7->setText(QApplication::translate("ExistingTables", "/", nullptr));
        labelMaxPage_2->setText(QApplication::translate("ExistingTables", "????", nullptr));
        prevButton_2->setText(QApplication::translate("ExistingTables", "<<", nullptr));
        label_12->setText(QApplication::translate("ExistingTables", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\265 \342\204\226:", nullptr));
        nextButton_2->setText(QApplication::translate("ExistingTables", ">>", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExistingTables: public Ui_ExistingTables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGTABLES_H
