/********************************************************************************
** Form generated from reading UI file 'payments.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTS_H
#define UI_PAYMENTS_H

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

class Ui_Payments
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_Search;
    QCheckBox *checkBox_Sorting;
    QCheckBox *checkBox_Filtr;
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
    QPushButton *addFilter;
    QPushButton *clearFilter;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *labelWhatKindSorting;
    QSpacerItem *horizontalSpacer;
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

    void setupUi(QWidget *Payments)
    {
        if (Payments->objectName().isEmpty())
            Payments->setObjectName(QString::fromUtf8("Payments"));
        Payments->resize(1035, 668);
        verticalLayout = new QVBoxLayout(Payments);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_Search = new QCheckBox(Payments);
        checkBox_Search->setObjectName(QString::fromUtf8("checkBox_Search"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        checkBox_Search->setFont(font);

        horizontalLayout_2->addWidget(checkBox_Search);

        checkBox_Sorting = new QCheckBox(Payments);
        checkBox_Sorting->setObjectName(QString::fromUtf8("checkBox_Sorting"));
        checkBox_Sorting->setFont(font);

        horizontalLayout_2->addWidget(checkBox_Sorting);

        checkBox_Filtr = new QCheckBox(Payments);
        checkBox_Filtr->setObjectName(QString::fromUtf8("checkBox_Filtr"));
        checkBox_Filtr->setFont(font);

        horizontalLayout_2->addWidget(checkBox_Filtr);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        refreshData = new QPushButton(Payments);
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
        label = new QLabel(Payments);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_9->addWidget(label);

        searchColumn = new QComboBox(Payments);
        searchColumn->setObjectName(QString::fromUtf8("searchColumn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        searchColumn->setFont(font2);

        horizontalLayout_9->addWidget(searchColumn);

        searchText = new QLineEdit(Payments);
        searchText->setObjectName(QString::fromUtf8("searchText"));
        searchText->setFont(font1);

        horizontalLayout_9->addWidget(searchText);

        checkBox = new QCheckBox(Payments);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font1);

        horizontalLayout_9->addWidget(checkBox);

        pushButton_search = new QPushButton(Payments);
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

        clearSearch = new QPushButton(Payments);
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
        label_3 = new QLabel(Payments);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_8->addWidget(label_3);

        sortingColumn = new QComboBox(Payments);
        sortingColumn->setObjectName(QString::fromUtf8("sortingColumn"));
        sortingColumn->setFont(font2);

        horizontalLayout_8->addWidget(sortingColumn);

        label_2 = new QLabel(Payments);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);

        horizontalLayout_8->addWidget(label_2);

        typeSorting = new QComboBox(Payments);
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

        sorting = new QCheckBox(Payments);
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setFont(font1);

        horizontalLayout_8->addWidget(sorting);

        horizontalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        addFilter = new QPushButton(Payments);
        addFilter->setObjectName(QString::fromUtf8("addFilter"));
        addFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon3.addFile(QString::fromUtf8(":/icons/resources/addFilter.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFilter->setIcon(icon3);
        addFilter->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(addFilter);

        clearFilter = new QPushButton(Payments);
        clearFilter->setObjectName(QString::fromUtf8("clearFilter"));
        clearFilter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon4.addFile(QString::fromUtf8(":/icons/resources/clearFilter.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearFilter->setIcon(icon4);
        clearFilter->setIconSize(QSize(24, 24));

        horizontalLayout_8->addWidget(clearFilter);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(Payments);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font1);

        horizontalLayout->addWidget(label_7);

        labelWhatKindSorting = new QLabel(Payments);
        labelWhatKindSorting->setObjectName(QString::fromUtf8("labelWhatKindSorting"));
        sizePolicy.setHeightForWidth(labelWhatKindSorting->sizePolicy().hasHeightForWidth());
        labelWhatKindSorting->setSizePolicy(sizePolicy);
        labelWhatKindSorting->setFont(font1);

        horizontalLayout->addWidget(labelWhatKindSorting);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(Payments);
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

        label_4 = new QLabel(Payments);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        labelCurrentPage = new QLabel(Payments);
        labelCurrentPage->setObjectName(QString::fromUtf8("labelCurrentPage"));
        labelCurrentPage->setFont(font2);

        horizontalLayout_6->addWidget(labelCurrentPage);

        label_5 = new QLabel(Payments);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_6->addWidget(label_5);

        labelMaxPage = new QLabel(Payments);
        labelMaxPage->setObjectName(QString::fromUtf8("labelMaxPage"));
        labelMaxPage->setFont(font2);

        horizontalLayout_6->addWidget(labelMaxPage);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        prevButton = new QPushButton(Payments);
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon5);
        prevButton->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(prevButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        label_6 = new QLabel(Payments);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        horizontalLayout_10->addWidget(label_6);

        pageNumberToNavigate = new QLineEdit(Payments);
        pageNumberToNavigate->setObjectName(QString::fromUtf8("pageNumberToNavigate"));
        pageNumberToNavigate->setMaximumSize(QSize(50, 16777215));
        pageNumberToNavigate->setFont(font1);

        horizontalLayout_10->addWidget(pageNumberToNavigate);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        nextButton = new QPushButton(Payments);
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon6);
        nextButton->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout_10);


        retranslateUi(Payments);

        QMetaObject::connectSlotsByName(Payments);
    } // setupUi

    void retranslateUi(QWidget *Payments)
    {
        Payments->setWindowTitle(QApplication::translate("Payments", "Form", nullptr));
        checkBox_Search->setText(QApplication::translate("Payments", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        checkBox_Sorting->setText(QApplication::translate("Payments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        checkBox_Filtr->setText(QApplication::translate("Payments", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        refreshData->setText(QString());
        label->setText(QApplication::translate("Payments", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox->setText(QApplication::translate("Payments", "\320\242\320\276\321\207\320\275\320\276\320\265 \n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton_search->setText(QString());
        clearSearch->setText(QString());
        label_3->setText(QApplication::translate("Payments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:", nullptr));
        label_2->setText(QApplication::translate("Payments", "\320\277\320\276", nullptr));
        typeSorting->setItemText(0, QApplication::translate("Payments", "\320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        typeSorting->setItemText(1, QApplication::translate("Payments", "\321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));

        sorting->setText(QApplication::translate("Payments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        addFilter->setText(QString());
        clearFilter->setText(QString());
        label_7->setText(QApplication::translate("Payments", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260:", nullptr));
        labelWhatKindSorting->setText(QApplication::translate("Payments", "\320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        label_4->setText(QApplication::translate("Payments", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260:", nullptr));
        labelCurrentPage->setText(QApplication::translate("Payments", "0", nullptr));
        label_5->setText(QApplication::translate("Payments", "/", nullptr));
        labelMaxPage->setText(QApplication::translate("Payments", "????", nullptr));
        prevButton->setText(QString());
        label_6->setText(QApplication::translate("Payments", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\265 \342\204\226:", nullptr));
        nextButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Payments: public Ui_Payments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTS_H
