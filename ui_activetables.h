/********************************************************************************
** Form generated from reading UI file 'activetables.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVETABLES_H
#define UI_ACTIVETABLES_H

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

class Ui_ActiveTables
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_Search;
    QCheckBox *checkBox_Sorting;
    QCheckBox *checkBox_Editing;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *refreshData;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QComboBox *searchColumn;
    QLineEdit *searchText;
    QCheckBox *checkBox;
    QPushButton *pushButton_search;
    QPushButton *clearSearch;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QComboBox *sortingColumn;
    QLabel *label_2;
    QComboBox *typeSorting;
    QCheckBox *sorting;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *labelWhatKindSorting;
    QSpacerItem *horizontalSpacer;
    QPushButton *addTable;
    QPushButton *editTable;
    QPushButton *deleteTable;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_4;
    QLabel *labelCurrentPage;
    QLabel *label_5;
    QLabel *labelMaxPage;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_6;
    QLineEdit *pageNumberToNavigate;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *nextButton;

    void setupUi(QWidget *ActiveTables)
    {
        if (ActiveTables->objectName().isEmpty())
            ActiveTables->setObjectName(QString::fromUtf8("ActiveTables"));
        ActiveTables->resize(1064, 460);
        verticalLayout = new QVBoxLayout(ActiveTables);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_Search = new QCheckBox(ActiveTables);
        checkBox_Search->setObjectName(QString::fromUtf8("checkBox_Search"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        checkBox_Search->setFont(font);

        horizontalLayout_2->addWidget(checkBox_Search);

        checkBox_Sorting = new QCheckBox(ActiveTables);
        checkBox_Sorting->setObjectName(QString::fromUtf8("checkBox_Sorting"));
        checkBox_Sorting->setFont(font);

        horizontalLayout_2->addWidget(checkBox_Sorting);

        checkBox_Editing = new QCheckBox(ActiveTables);
        checkBox_Editing->setObjectName(QString::fromUtf8("checkBox_Editing"));
        checkBox_Editing->setFont(font);

        horizontalLayout_2->addWidget(checkBox_Editing);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        refreshData = new QPushButton(ActiveTables);
        refreshData->setObjectName(QString::fromUtf8("refreshData"));
        refreshData->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshData->setIcon(icon);
        refreshData->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(refreshData);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(ActiveTables);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_9->addWidget(label);

        searchColumn = new QComboBox(ActiveTables);
        searchColumn->setObjectName(QString::fromUtf8("searchColumn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        searchColumn->setFont(font2);

        horizontalLayout_9->addWidget(searchColumn);

        searchText = new QLineEdit(ActiveTables);
        searchText->setObjectName(QString::fromUtf8("searchText"));
        searchText->setFont(font1);

        horizontalLayout_9->addWidget(searchText);

        checkBox = new QCheckBox(ActiveTables);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font1);

        horizontalLayout_9->addWidget(checkBox);

        pushButton_search = new QPushButton(ActiveTables);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_search->setIcon(icon1);
        pushButton_search->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(pushButton_search);

        clearSearch = new QPushButton(ActiveTables);
        clearSearch->setObjectName(QString::fromUtf8("clearSearch"));
        clearSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/resources/clearSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearSearch->setIcon(icon2);
        clearSearch->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(clearSearch);

        horizontalSpacer_14 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(ActiveTables);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_8->addWidget(label_3);

        sortingColumn = new QComboBox(ActiveTables);
        sortingColumn->setObjectName(QString::fromUtf8("sortingColumn"));
        sortingColumn->setFont(font2);

        horizontalLayout_8->addWidget(sortingColumn);

        label_2 = new QLabel(ActiveTables);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);

        horizontalLayout_8->addWidget(label_2);

        typeSorting = new QComboBox(ActiveTables);
        typeSorting->addItem(QString());
        typeSorting->addItem(QString());
        typeSorting->setObjectName(QString::fromUtf8("typeSorting"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(typeSorting->sizePolicy().hasHeightForWidth());
        typeSorting->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        typeSorting->setFont(font3);

        horizontalLayout_8->addWidget(typeSorting);

        sorting = new QCheckBox(ActiveTables);
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setFont(font1);

        horizontalLayout_8->addWidget(sorting);

        horizontalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(ActiveTables);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font1);

        horizontalLayout->addWidget(label_7);

        labelWhatKindSorting = new QLabel(ActiveTables);
        labelWhatKindSorting->setObjectName(QString::fromUtf8("labelWhatKindSorting"));
        sizePolicy.setHeightForWidth(labelWhatKindSorting->sizePolicy().hasHeightForWidth());
        labelWhatKindSorting->setSizePolicy(sizePolicy);
        labelWhatKindSorting->setFont(font1);

        horizontalLayout->addWidget(labelWhatKindSorting);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addTable = new QPushButton(ActiveTables);
        addTable->setObjectName(QString::fromUtf8("addTable"));
        addTable->setFont(font3);
        addTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addTable->setIcon(icon3);
        addTable->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(addTable);

        editTable = new QPushButton(ActiveTables);
        editTable->setObjectName(QString::fromUtf8("editTable"));
        editTable->setFont(font3);
        editTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/resources/edited.png"), QSize(), QIcon::Normal, QIcon::Off);
        editTable->setIcon(icon4);
        editTable->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(editTable);

        deleteTable = new QPushButton(ActiveTables);
        deleteTable->setObjectName(QString::fromUtf8("deleteTable"));
        deleteTable->setFont(font3);
        deleteTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteTable->setIcon(icon5);
        deleteTable->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(deleteTable);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(ActiveTables);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(10);
        tableView->setFont(font4);

        verticalLayout->addWidget(tableView);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        label_4 = new QLabel(ActiveTables);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        labelCurrentPage = new QLabel(ActiveTables);
        labelCurrentPage->setObjectName(QString::fromUtf8("labelCurrentPage"));
        labelCurrentPage->setFont(font2);

        horizontalLayout_6->addWidget(labelCurrentPage);

        label_5 = new QLabel(ActiveTables);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_6->addWidget(label_5);

        labelMaxPage = new QLabel(ActiveTables);
        labelMaxPage->setObjectName(QString::fromUtf8("labelMaxPage"));
        labelMaxPage->setFont(font2);

        horizontalLayout_6->addWidget(labelMaxPage);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, -1, 9, -1);
        prevButton = new QPushButton(ActiveTables);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Segoe UI"));
        font5.setPointSize(18);
        prevButton->setFont(font5);
        prevButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon6);
        prevButton->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(prevButton);

        horizontalSpacer_15 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        label_6 = new QLabel(ActiveTables);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        horizontalLayout_10->addWidget(label_6);

        pageNumberToNavigate = new QLineEdit(ActiveTables);
        pageNumberToNavigate->setObjectName(QString::fromUtf8("pageNumberToNavigate"));
        pageNumberToNavigate->setMaximumSize(QSize(50, 16777215));
        pageNumberToNavigate->setFont(font1);

        horizontalLayout_10->addWidget(pageNumberToNavigate);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        nextButton = new QPushButton(ActiveTables);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setFont(font5);
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: white;\n"
"    border: 2px solid black; \n"
"    border-radius: 10px;\n"
"    border-radius: 10px;\n"
"    padding-left: 15px;\n"
"    padding-right: 15px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(100, 88, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: rgba(220, 60, 190, 255);\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon7);
        nextButton->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout_10);


        retranslateUi(ActiveTables);

        QMetaObject::connectSlotsByName(ActiveTables);
    } // setupUi

    void retranslateUi(QWidget *ActiveTables)
    {
        ActiveTables->setWindowTitle(QApplication::translate("ActiveTables", "Form", nullptr));
        checkBox_Search->setText(QApplication::translate("ActiveTables", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        checkBox_Sorting->setText(QApplication::translate("ActiveTables", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        checkBox_Editing->setText(QApplication::translate("ActiveTables", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        refreshData->setText(QString());
        label->setText(QApplication::translate("ActiveTables", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox->setText(QApplication::translate("ActiveTables", "\320\242\320\276\321\207\320\275\320\276\320\265 \n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton_search->setText(QString());
        clearSearch->setText(QString());
        label_3->setText(QApplication::translate("ActiveTables", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:", nullptr));
        label_2->setText(QApplication::translate("ActiveTables", "\320\277\320\276", nullptr));
        typeSorting->setItemText(0, QApplication::translate("ActiveTables", "\320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        typeSorting->setItemText(1, QApplication::translate("ActiveTables", "\321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));

        sorting->setText(QApplication::translate("ActiveTables", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_7->setText(QApplication::translate("ActiveTables", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260:", nullptr));
        labelWhatKindSorting->setText(QApplication::translate("ActiveTables", "\320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        addTable->setText(QString());
        label_4->setText(QApplication::translate("ActiveTables", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260:", nullptr));
        labelCurrentPage->setText(QApplication::translate("ActiveTables", "0", nullptr));
        label_5->setText(QApplication::translate("ActiveTables", "/", nullptr));
        labelMaxPage->setText(QApplication::translate("ActiveTables", "????", nullptr));
        prevButton->setText(QString());
        label_6->setText(QApplication::translate("ActiveTables", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\265 \342\204\226:", nullptr));
        nextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActiveTables: public Ui_ActiveTables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVETABLES_H
