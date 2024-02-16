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

class Ui_AllUsers
{
public:
    QVBoxLayout *verticalLayout;
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
    QPushButton *moreDetailed;
    QPushButton *addTable;
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
    QLabel *status;

    void setupUi(QWidget *AllUsers)
    {
        if (AllUsers->objectName().isEmpty())
            AllUsers->setObjectName(QString::fromUtf8("AllUsers"));
        AllUsers->resize(1015, 640);
        verticalLayout = new QVBoxLayout(AllUsers);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(AllUsers);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout_9->addWidget(label);

        searchColumn = new QComboBox(AllUsers);
        searchColumn->setObjectName(QString::fromUtf8("searchColumn"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        searchColumn->setFont(font1);

        horizontalLayout_9->addWidget(searchColumn);

        searchText = new QLineEdit(AllUsers);
        searchText->setObjectName(QString::fromUtf8("searchText"));
        searchText->setFont(font);

        horizontalLayout_9->addWidget(searchText);

        checkBox = new QCheckBox(AllUsers);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        horizontalLayout_9->addWidget(checkBox);

        pushButton_search = new QPushButton(AllUsers);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_search->setIcon(icon);
        pushButton_search->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(pushButton_search);

        clearSearch = new QPushButton(AllUsers);
        clearSearch->setObjectName(QString::fromUtf8("clearSearch"));
        clearSearch->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        clearSearch->setIcon(icon1);
        clearSearch->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(clearSearch);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_3 = new QLabel(AllUsers);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_8->addWidget(label_3);

        sortingColumn = new QComboBox(AllUsers);
        sortingColumn->setObjectName(QString::fromUtf8("sortingColumn"));
        sortingColumn->setFont(font1);

        horizontalLayout_8->addWidget(sortingColumn);

        label_2 = new QLabel(AllUsers);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);

        horizontalLayout_8->addWidget(label_2);

        typeSorting = new QComboBox(AllUsers);
        typeSorting->addItem(QString());
        typeSorting->addItem(QString());
        typeSorting->setObjectName(QString::fromUtf8("typeSorting"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(typeSorting->sizePolicy().hasHeightForWidth());
        typeSorting->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        typeSorting->setFont(font2);

        horizontalLayout_8->addWidget(typeSorting);

        sorting = new QCheckBox(AllUsers);
        sorting->setObjectName(QString::fromUtf8("sorting"));
        sorting->setFont(font);

        horizontalLayout_8->addWidget(sorting);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_13);

        moreDetailed = new QPushButton(AllUsers);
        moreDetailed->setObjectName(QString::fromUtf8("moreDetailed"));
        moreDetailed->setFont(font2);
        moreDetailed->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_8->addWidget(moreDetailed);

        addTable = new QPushButton(AllUsers);
        addTable->setObjectName(QString::fromUtf8("addTable"));
        addTable->setFont(font2);
        addTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_8->addWidget(addTable);


        verticalLayout->addLayout(horizontalLayout_8);

        tableView = new QTableView(AllUsers);
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

        label_4 = new QLabel(AllUsers);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_6->addWidget(label_4);

        labelCurrentPage = new QLabel(AllUsers);
        labelCurrentPage->setObjectName(QString::fromUtf8("labelCurrentPage"));
        labelCurrentPage->setFont(font1);

        horizontalLayout_6->addWidget(labelCurrentPage);

        label_5 = new QLabel(AllUsers);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        labelMaxPage = new QLabel(AllUsers);
        labelMaxPage->setObjectName(QString::fromUtf8("labelMaxPage"));
        labelMaxPage->setFont(font1);

        horizontalLayout_6->addWidget(labelMaxPage);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        prevButton = new QPushButton(AllUsers);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Segoe UI"));
        font4.setPointSize(18);
        prevButton->setFont(font4);
        prevButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_10->addWidget(prevButton);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_15);

        label_6 = new QLabel(AllUsers);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_10->addWidget(label_6);

        pageNumberToNavigate = new QLineEdit(AllUsers);
        pageNumberToNavigate->setObjectName(QString::fromUtf8("pageNumberToNavigate"));
        pageNumberToNavigate->setMaximumSize(QSize(50, 16777215));
        pageNumberToNavigate->setFont(font);

        horizontalLayout_10->addWidget(pageNumberToNavigate);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_16);

        nextButton = new QPushButton(AllUsers);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setFont(font4);
        nextButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout_10->addWidget(nextButton);


        verticalLayout->addLayout(horizontalLayout_10);

        status = new QLabel(AllUsers);
        status->setObjectName(QString::fromUtf8("status"));

        verticalLayout->addWidget(status);


        retranslateUi(AllUsers);

        QMetaObject::connectSlotsByName(AllUsers);
    } // setupUi

    void retranslateUi(QWidget *AllUsers)
    {
        AllUsers->setWindowTitle(QApplication::translate("AllUsers", "Form", nullptr));
        label->setText(QApplication::translate("AllUsers", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        checkBox->setText(QApplication::translate("AllUsers", "\320\242\320\276\321\207\320\275\320\276\320\265 \n"
"\321\201\320\276\320\262\320\277\320\260\320\264\320\265\320\275\320\270\320\265", nullptr));
        pushButton_search->setText(QString());
        clearSearch->setText(QString());
        label_3->setText(QApplication::translate("AllUsers", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206:", nullptr));
        label_2->setText(QApplication::translate("AllUsers", "\320\277\320\276", nullptr));
        typeSorting->setItemText(0, QApplication::translate("AllUsers", "\320\237\320\276 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", nullptr));
        typeSorting->setItemText(1, QApplication::translate("AllUsers", "\320\237\320\276 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\216", nullptr));

        sorting->setText(QApplication::translate("AllUsers", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        moreDetailed->setText(QApplication::translate("AllUsers", "\320\237\320\276\320\264\321\200\320\276\320\261\320\275\320\265\320\265", nullptr));
        addTable->setText(QApplication::translate("AllUsers", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_4->setText(QApplication::translate("AllUsers", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\260:", nullptr));
        labelCurrentPage->setText(QApplication::translate("AllUsers", "1", nullptr));
        label_5->setText(QApplication::translate("AllUsers", "/", nullptr));
        labelMaxPage->setText(QApplication::translate("AllUsers", "????", nullptr));
        prevButton->setText(QApplication::translate("AllUsers", "<<", nullptr));
        label_6->setText(QApplication::translate("AllUsers", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\321\202\321\200\320\260\320\275\320\270\321\206\320\265 \342\204\226:", nullptr));
        nextButton->setText(QApplication::translate("AllUsers", ">>", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AllUsers: public Ui_AllUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLUSERS_H
