/********************************************************************************
** Form generated from reading UI file 'window_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_ADMIN_H
#define UI_WINDOW_ADMIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Admin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QVBoxLayout *verticalLayout;
    QLabel *FIO_employee;
    QLabel *post;
    QPushButton *buttonExit;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *banList;
    QLabel *label_4;
    QPushButton *stuffUsers;
    QPushButton *buttonLoanApplocations;
    QLabel *label_5;
    QLabel *label_3;
    QPushButton *users;
    QLabel *label_2;
    QPushButton *activeTables;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *photo;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *Window_Admin)
    {
        if (Window_Admin->objectName().isEmpty())
            Window_Admin->setObjectName(QString::fromUtf8("Window_Admin"));
        Window_Admin->resize(948, 665);
        Window_Admin->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Window_Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background-color: rgb(51, 41, 123);\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"	border-radius: 10px;\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);

        gridLayout->addWidget(tabWidget, 0, 2, 15, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, -1, 5, -1);
        FIO_employee = new QLabel(centralwidget);
        FIO_employee->setObjectName(QString::fromUtf8("FIO_employee"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        FIO_employee->setFont(font);
        FIO_employee->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(FIO_employee);

        post = new QLabel(centralwidget);
        post->setObjectName(QString::fromUtf8("post"));
        post->setFont(font);
        post->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout->addWidget(post);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        buttonExit = new QPushButton(centralwidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        buttonExit->setFont(font);
        buttonExit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonExit->setIcon(icon);
        buttonExit->setIconSize(QSize(32, 32));

        gridLayout->addWidget(buttonExit, 13, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label->setScaledContents(true);

        gridLayout_3->addWidget(label, 4, 2, 1, 1);

        banList = new QPushButton(centralwidget);
        banList->setObjectName(QString::fromUtf8("banList"));
        banList->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        banList->setFont(font1);
        banList->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(banList, 3, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_4->setScaledContents(true);

        gridLayout_3->addWidget(label_4, 2, 2, 1, 1);

        stuffUsers = new QPushButton(centralwidget);
        stuffUsers->setObjectName(QString::fromUtf8("stuffUsers"));
        stuffUsers->setMinimumSize(QSize(0, 40));
        stuffUsers->setFont(font1);
        stuffUsers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(stuffUsers, 2, 1, 1, 1);

        buttonLoanApplocations = new QPushButton(centralwidget);
        buttonLoanApplocations->setObjectName(QString::fromUtf8("buttonLoanApplocations"));
        buttonLoanApplocations->setMinimumSize(QSize(0, 40));
        buttonLoanApplocations->setFont(font1);
        buttonLoanApplocations->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(buttonLoanApplocations, 4, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_5->setScaledContents(true);

        gridLayout_3->addWidget(label_5, 3, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_3->setScaledContents(true);

        gridLayout_3->addWidget(label_3, 1, 2, 1, 1);

        users = new QPushButton(centralwidget);
        users->setObjectName(QString::fromUtf8("users"));
        users->setMinimumSize(QSize(0, 40));
        users->setFont(font1);
        users->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(users, 1, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_2->setScaledContents(true);

        gridLayout_3->addWidget(label_2, 0, 2, 1, 1);

        activeTables = new QPushButton(centralwidget);
        activeTables->setObjectName(QString::fromUtf8("activeTables"));
        activeTables->setMinimumSize(QSize(0, 40));
        activeTables->setFont(font1);
        activeTables->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(activeTables, 0, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(pushButton, 5, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_6->setScaledContents(true);

        gridLayout_3->addWidget(label_6, 5, 2, 1, 1);


        gridLayout->addLayout(gridLayout_3, 7, 0, 2, 2);

        photo = new QLabel(centralwidget);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(65, 65));
        photo->setMaximumSize(QSize(65, 65));

        gridLayout->addWidget(photo, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 12, 0, 1, 2);

        Window_Admin->setCentralWidget(centralwidget);

        retranslateUi(Window_Admin);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Window_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Admin)
    {
        Window_Admin->setWindowTitle(QApplication::translate("Window_Admin", "MainWindow", nullptr));
        FIO_employee->setText(QApplication::translate("Window_Admin", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\230.", nullptr));
        post->setText(QApplication::translate("Window_Admin", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        buttonExit->setText(QApplication::translate("Window_Admin", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        banList->setText(QApplication::translate("Window_Admin", "\320\247\321\221\321\200\320\275\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        label_4->setText(QString());
        stuffUsers->setText(QApplication::translate("Window_Admin", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        buttonLoanApplocations->setText(QApplication::translate("Window_Admin", "\320\227\320\260\321\217\320\262\320\272\320\270 \320\275\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\321\213", nullptr));
        label_5->setText(QString());
        label_3->setText(QString());
        users->setText(QApplication::translate("Window_Admin", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        label_2->setText(QString());
        activeTables->setText(QApplication::translate("Window_Admin", "\320\230\320\263\321\200\320\276\320\262\321\213\320\265 \321\201\321\202\320\276\320\273\321\213", nullptr));
        pushButton->setText(QApplication::translate("Window_Admin", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \321\202\321\200\320\260\320\275\320\267\320\260\320\272\321\206\320\270\320\271\n"
"(\320\277\320\273\320\260\321\202\320\265\320\266\320\265\320\271)?", nullptr));
        label_6->setText(QString());
        photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Window_Admin: public Ui_Window_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ADMIN_H
