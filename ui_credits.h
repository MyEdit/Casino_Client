/********************************************************************************
** Form generated from reading UI file 'credits.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITS_H
#define UI_CREDITS_H

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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credits
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_Sorting;
    QRadioButton *radioButton_Search;
    QRadioButton *radioButton_Filtr;
    QRadioButton *radioButton_Editing;
    QRadioButton *radioButton;
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
    QPushButton *addFilter;
    QPushButton *clearFilter;
    QPushButton *addCredit;
    QPushButton *editCredit;
    QPushButton *deleteCredit;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *prevButton;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_4;
    QLineEdit *currentPage;
    QLabel *label_5;
    QLabel *labelMaxPage;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *nextButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLabel *labelWhatKindSorting;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QLabel *labelWhatKindFilter;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Credits)
    {
        if (Credits->objectName().isEmpty())
            Credits->setObjectName(QString::fromUtf8("Credits"));
        Credits->resize(994, 585);
        verticalLayout = new QVBoxLayout(Credits);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton_Sorting = new QRadioButton(Credits);
        radioButton_Sorting->setObjectName(QString::fromUtf8("radioButton_Sorting"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        radioButton_Sorting->setFont(font);

        horizontalLayout_2->addWidget(radioButton_Sorting);

        radioButton_Search = new QRadioButton(Credits);
        radioButton_Search->setObjectName(QString::fromUtf8("radioButton_Search"));
        radioButton_Search->setFont(font);

        horizontalLayout_2->addWidget(radioButton_Search);

        radioButton_Filtr = new QRadioButton(Credits);
        radioButton_Filtr->setObjectName(QString::fromUtf8("radioButton_Filtr"));
        radioButton_Filtr->setFont(font);

        horizontalLayout_2->addWidget(radioButton_Filtr);

        radioButton_Editing = new QRadioButton(Credits);
        radioButton_Editing->setObjectName(QString::fromUtf8("radioButton_Editing"));
        radioButton_Editing->setFont(font);

        horizontalLayout_2->addWidget(radioButton_Editing);

        radioButton = new QRadioButton(Credits);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setFont(font);

        horizontalLayout_2->addWidget(radioButton);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        refreshData = new QPushButton(Credits);
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
        label = new QLabel(Credits);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout_9->addWidget(label);

        searchColumn = new QComboBox(Credits);
        searchColumn->setObjectName(QString::fromUtf8("searchColumn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        searchColumn->setFont(font2);

        horizontalLayout_9->addWidget(searchColumn);

        searchText = new QLineEdit(Credits);
        searchText->setObjectName(QString::fromUtf8("searchText"));
        searchText->setFont(font1);

        horizontalLayout_9->addWidget(searchText);

        checkBox = new QCheckBox(Credits);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(11);
        checkBox->setFont(font3);

        horizontalLayout_9->addWidget(checkBox);

        pushButton_search = new QPushButton(Credits);
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

        clearSearch = new QPushButton(Credits);
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
        label_3 = new QLabel(Credits);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_8->addWidget(label_3);

        sortingColumn = new QComboBox(Credits);
        sortingColumn->setObjectName(QString::fromUtf8("sortingColumn"));
        sortingColumn->setFont(font2);

        horizontalLayout_8->addWidget(sortingColumn);

        label_2 = new QLabel(Credits);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);

        horizontalLayout_8->addWidget(label_2);

        typeSorting = new QComboBox(Credits);
        typeSorting->addItem(QString());
        typeSorting->addItem(QString());
        typeSorting->setObjectName(QString::fromUtf8("typeSorting"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(typeSorting->sizePolicy().hasHeightForWidth());
        typeSorting->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        typeSorting->setFont(font4);

        horizontalLayout_8->addWidget(typeSorting);

        sorting = new QCheckBox(Credits);
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setFont(font1);

        horizontalLayout_8->addWidget(sorting);

        addFilter = new QPushButton(Credits);
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
        addFilter->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(addFilter);

        clearFilter = new QPushButton(Credits);
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
        clearFilter->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(clearFilter);

        addCredit = new QPushButton(Credits);
        addCredit->setObjectName(QString::fromUtf8("addCredit"));
        addCredit->setFont(font4);
        addCredit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        icon5.addFile(QString::fromUtf8(":/icons/resources/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addCredit->setIcon(icon5);
        addCredit->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(addCredit);

        editCredit = new QPushButton(Credits);
        editCredit->setObjectName(QString::fromUtf8("editCredit"));
        editCredit->setFont(font4);
        editCredit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/resources/edited.png"), QSize(), QIcon::Normal, QIcon::Off);
        editCredit->setIcon(icon6);
        editCredit->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(editCredit);

        deleteCredit = new QPushButton(Credits);
        deleteCredit->setObjectName(QString::fromUtf8("deleteCredit"));
        deleteCredit->setFont(font4);
        deleteCredit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteCredit->setIcon(icon7);
        deleteCredit->setIconSize(QSize(32, 32));

        horizontalLayout_8->addWidget(deleteCredit);

        horizontalSpacer_13 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        prevButton = new QPushButton(Credits);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        prevButton->setIcon(icon8);
        prevButton->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(prevButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        label_4 = new QLabel(Credits);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_10->addWidget(label_4);

        currentPage = new QLineEdit(Credits);
        currentPage->setObjectName(QString::fromUtf8("currentPage"));
        currentPage->setMaximumSize(QSize(50, 16777215));
        currentPage->setFont(font2);
        currentPage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(currentPage);

        label_5 = new QLabel(Credits);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_10->addWidget(label_5);

        labelMaxPage = new QLabel(Credits);
        labelMaxPage->setObjectName(QString::fromUtf8("labelMaxPage"));
        labelMaxPage->setFont(font2);

        horizontalLayout_10->addWidget(labelMaxPage);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        nextButton = new QPushButton(Credits);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextButton->setIcon(icon9);
        nextButton->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout_10);

        tableView = new QTableView(Credits);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Segoe UI"));
        font6.setPointSize(10);
        tableView->setFont(font6);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(Credits);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font1);

        horizontalLayout->addWidget(label_7);

        labelWhatKindSorting = new QLabel(Credits);
        labelWhatKindSorting->setObjectName(QString::fromUtf8("labelWhatKindSorting"));
        sizePolicy.setHeightForWidth(labelWhatKindSorting->sizePolicy().hasHeightForWidth());
        labelWhatKindSorting->setSizePolicy(sizePolicy);
        labelWhatKindSorting->setFont(font1);

        horizontalLayout->addWidget(labelWhatKindSorting);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_9 = new QLabel(Credits);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        horizontalLayout_3->addWidget(label_9);

        labelWhatKindFilter = new QLabel(Credits);
        labelWhatKindFilter->setObjectName(QString::fromUtf8("labelWhatKindFilter"));
        labelWhatKindFilter->setFont(font1);

        horizontalLayout_3->addWidget(labelWhatKindFilter);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Credits);

        QMetaObject::connectSlotsByName(Credits);
    } // setupUi

    void retranslateUi(QWidget *Credits)
    {
        Credits->setWindowTitle(QApplication::translate("Credits", "Form", nullptr));
        radioButton_Sorting->setText(QApplication::translate("Credits", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        radioButton_Search->setText(QApplication::translate("Credits", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        radioButton_Filtr->setText(QApplication::translate("Credits", "\320\244\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        radioButton_Editing->setText(QApplication::translate("Credits", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        radioButton->setText(QApplication::translate("Credits", "\320\241\320\272\321\200\321\213\321\202\321\214 \320\270\320\275\321\201\321\202\321\203\321\200\320\274\320\265\320\275\321\202\321\213", nullptr));
        refreshData->setText(QString());
        label->setText(QApplication::translate("Credits", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox->setText(QApplication::translate("Credits", "\320\242\320\276\321\207\320\275\320\276\320\265 \n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton_search->setText(QString());
        clearSearch->setText(QString());
        label_3->setText(QApplication::translate("Credits", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:", nullptr));
        label_2->setText(QApplication::translate("Credits", "\320\277\320\276", nullptr));
        typeSorting->setItemText(0, QApplication::translate("Credits", "\320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        typeSorting->setItemText(1, QApplication::translate("Credits", "\321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));

        sorting->setText(QApplication::translate("Credits", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        addFilter->setText(QString());
        clearFilter->setText(QString());
        addCredit->setText(QString());
        prevButton->setText(QString());
        label_4->setText(QApplication::translate("Credits", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260:", nullptr));
        label_5->setText(QApplication::translate("Credits", "/", nullptr));
        labelMaxPage->setText(QApplication::translate("Credits", "????", nullptr));
        nextButton->setText(QString());
        label_7->setText(QApplication::translate("Credits", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260:", nullptr));
        labelWhatKindSorting->setText(QApplication::translate("Credits", "\320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        label_9->setText(QApplication::translate("Credits", "\320\244\320\270\320\273\321\214\321\202\321\200:", nullptr));
        labelWhatKindFilter->setText(QApplication::translate("Credits", "\320\276\321\202\321\201\321\203\321\202\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credits: public Ui_Credits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITS_H
