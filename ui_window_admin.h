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
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *buttonExit;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QPushButton *profit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *stuffUsers;
    QLabel *label_4;
    QPushButton *activeTables;
    QPushButton *banList;
    QPushButton *credits;
    QLabel *label_7;
    QLabel *label_3;
    QPushButton *users;
    QSpacerItem *horizontalSpacer;
    QPushButton *payments;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *photo;
    QVBoxLayout *verticalLayout;
    QLabel *fullNameEmployee;
    QLabel *post;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonChangeUser;

    void setupUi(QMainWindow *Window_Admin)
    {
        if (Window_Admin->objectName().isEmpty())
            Window_Admin->setObjectName(QString::fromUtf8("Window_Admin"));
        Window_Admin->resize(1072, 678);
        Window_Admin->setMinimumSize(QSize(1000, 0));
        Window_Admin->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Window_Admin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background-color: rgb(51, 41, 123);\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        buttonExit = new QPushButton(centralwidget);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        buttonExit->setFont(font);
        buttonExit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonExit->setIcon(icon);
        buttonExit->setIconSize(QSize(32, 32));

        gridLayout->addWidget(buttonExit, 15, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 13, 0, 1, 2);

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

        gridLayout->addWidget(tabWidget, 0, 2, 17, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_6->setScaledContents(true);

        gridLayout_3->addWidget(label_6, 5, 2, 1, 1);

        profit = new QPushButton(centralwidget);
        profit->setObjectName(QString::fromUtf8("profit"));
        profit->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        profit->setFont(font1);
        profit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));

        gridLayout_3->addWidget(profit, 6, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label->setScaledContents(true);

        gridLayout_3->addWidget(label, 4, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_2->setScaledContents(true);

        gridLayout_3->addWidget(label_2, 0, 2, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_5->setScaledContents(true);

        gridLayout_3->addWidget(label_5, 3, 2, 1, 1);

        stuffUsers = new QPushButton(centralwidget);
        stuffUsers->setObjectName(QString::fromUtf8("stuffUsers"));
        stuffUsers->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        stuffUsers->setFont(font2);
        stuffUsers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));

        gridLayout_3->addWidget(stuffUsers, 2, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_4->setScaledContents(true);

        gridLayout_3->addWidget(label_4, 2, 2, 1, 1);

        activeTables = new QPushButton(centralwidget);
        activeTables->setObjectName(QString::fromUtf8("activeTables"));
        activeTables->setMinimumSize(QSize(0, 40));
        activeTables->setFont(font2);
        activeTables->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}"));

        gridLayout_3->addWidget(activeTables, 0, 1, 1, 1);

        banList = new QPushButton(centralwidget);
        banList->setObjectName(QString::fromUtf8("banList"));
        banList->setMinimumSize(QSize(0, 40));
        banList->setFont(font2);
        banList->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));

        gridLayout_3->addWidget(banList, 3, 1, 1, 1);

        credits = new QPushButton(centralwidget);
        credits->setObjectName(QString::fromUtf8("credits"));
        credits->setMinimumSize(QSize(0, 40));
        credits->setFont(font2);
        credits->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));

        gridLayout_3->addWidget(credits, 4, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_7->setScaledContents(true);

        gridLayout_3->addWidget(label_7, 6, 2, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_3->setScaledContents(true);

        gridLayout_3->addWidget(label_3, 1, 2, 1, 1);

        users = new QPushButton(centralwidget);
        users->setObjectName(QString::fromUtf8("users"));
        users->setMinimumSize(QSize(0, 40));
        users->setFont(font2);
        users->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));

        gridLayout_3->addWidget(users, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        payments = new QPushButton(centralwidget);
        payments->setObjectName(QString::fromUtf8("payments"));
        payments->setMinimumSize(QSize(175, 40));
        payments->setFont(font2);
        payments->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));

        gridLayout_3->addWidget(payments, 5, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 8, 0, 2, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        photo = new QLabel(centralwidget);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(65, 65));
        photo->setMaximumSize(QSize(65, 65));

        horizontalLayout->addWidget(photo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, -1, 5, -1);
        fullNameEmployee = new QLabel(centralwidget);
        fullNameEmployee->setObjectName(QString::fromUtf8("fullNameEmployee"));
        fullNameEmployee->setMinimumSize(QSize(20, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        fullNameEmployee->setFont(font3);
        fullNameEmployee->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        fullNameEmployee->setAlignment(Qt::AlignCenter);
        fullNameEmployee->setWordWrap(true);

        verticalLayout->addWidget(fullNameEmployee);

        post = new QLabel(centralwidget);
        post->setObjectName(QString::fromUtf8("post"));
        post->setFont(font3);
        post->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        post->setAlignment(Qt::AlignCenter);
        post->setWordWrap(true);

        verticalLayout->addWidget(post);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);

        buttonChangeUser = new QPushButton(centralwidget);
        buttonChangeUser->setObjectName(QString::fromUtf8("buttonChangeUser"));
        buttonChangeUser->setMinimumSize(QSize(250, 0));
        buttonChangeUser->setFont(font2);
        buttonChangeUser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"font-weight: bold;\n"
"}s"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resources/ChangeUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonChangeUser->setIcon(icon1);
        buttonChangeUser->setIconSize(QSize(32, 32));

        gridLayout->addWidget(buttonChangeUser, 14, 0, 1, 2);

        Window_Admin->setCentralWidget(centralwidget);

        retranslateUi(Window_Admin);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Window_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Admin)
    {
        Window_Admin->setWindowTitle(QApplication::translate("Window_Admin", "\320\234\320\265\320\275\321\216 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        buttonExit->setText(QApplication::translate("Window_Admin", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        label_6->setText(QString());
        profit->setText(QApplication::translate("Window_Admin", "\320\237\321\200\320\270\320\261\321\213\320\273\321\214 \320\272\320\260\320\267\320\270\320\275\320\276", nullptr));
        label_2->setText(QString());
        label_5->setText(QString());
        stuffUsers->setText(QApplication::translate("Window_Admin", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        label_4->setText(QString());
        activeTables->setText(QApplication::translate("Window_Admin", "\320\230\320\263\321\200\320\276\320\262\321\213\320\265 \321\201\321\202\320\276\320\273\321\213", nullptr));
        banList->setText(QApplication::translate("Window_Admin", "\320\247\321\221\321\200\320\275\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        credits->setText(QApplication::translate("Window_Admin", "\320\227\320\260\321\217\320\262\320\272\320\270 \320\275\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\321\213", nullptr));
        label_7->setText(QString());
        label_3->setText(QString());
        users->setText(QApplication::translate("Window_Admin", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        payments->setText(QApplication::translate("Window_Admin", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \321\202\321\200\320\260\320\275\320\267\320\260\320\272\321\206\320\270\320\271", nullptr));
        photo->setText(QString());
        fullNameEmployee->setText(QApplication::translate("Window_Admin", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\230.", nullptr));
        post->setText(QApplication::translate("Window_Admin", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        buttonChangeUser->setText(QApplication::translate("Window_Admin", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Admin: public Ui_Window_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ADMIN_H
