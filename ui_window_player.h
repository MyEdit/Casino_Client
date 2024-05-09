/********************************************************************************
** Form generated from reading UI file 'window_player.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PLAYER_H
#define UI_WINDOW_PLAYER_H

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

class Ui_Window_Player
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *buttonExit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *photo;
    QVBoxLayout *verticalLayout;
    QLabel *fullNamePlayer;
    QLabel *balance;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *replenish;
    QLabel *label_3;
    QPushButton *credits;
    QPushButton *gameTables;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QTabWidget *tabWidget;
    QPushButton *buttonChangeUser;

    void setupUi(QMainWindow *Window_Player)
    {
        if (Window_Player->objectName().isEmpty())
            Window_Player->setObjectName(QString::fromUtf8("Window_Player"));
        Window_Player->resize(1064, 712);
        Window_Player->setMinimumSize(QSize(1000, 0));
        centralwidget = new QWidget(Window_Player);
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
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonExit->setIcon(icon);
        buttonExit->setIconSize(QSize(32, 32));

        gridLayout->addWidget(buttonExit, 6, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        photo = new QLabel(centralwidget);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(65, 65));
        photo->setMaximumSize(QSize(65, 65));

        horizontalLayout->addWidget(photo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, -1, 5, -1);
        fullNamePlayer = new QLabel(centralwidget);
        fullNamePlayer->setObjectName(QString::fromUtf8("fullNamePlayer"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        fullNamePlayer->setFont(font1);
        fullNamePlayer->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        fullNamePlayer->setAlignment(Qt::AlignCenter);
        fullNamePlayer->setWordWrap(true);

        verticalLayout->addWidget(fullNamePlayer);

        balance = new QLabel(centralwidget);
        balance->setObjectName(QString::fromUtf8("balance"));
        balance->setFont(font1);
        balance->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        balance->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(balance);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(250, 97, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        replenish = new QPushButton(centralwidget);
        replenish->setObjectName(QString::fromUtf8("replenish"));
        replenish->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        replenish->setFont(font2);
        replenish->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_2->addWidget(replenish, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_3->setScaledContents(true);

        gridLayout_2->addWidget(label_3, 2, 2, 1, 1);

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
"}"));

        gridLayout_2->addWidget(credits, 2, 1, 1, 1);

        gameTables = new QPushButton(centralwidget);
        gameTables->setObjectName(QString::fromUtf8("gameTables"));
        gameTables->setMinimumSize(QSize(0, 40));
        gameTables->setFont(font2);
        gameTables->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_2->addWidget(gameTables, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_2->setScaledContents(true);

        gridLayout_2->addWidget(label_2, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 0, 1, 2);

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

        gridLayout->addWidget(tabWidget, 0, 2, 7, 1);

        buttonChangeUser = new QPushButton(centralwidget);
        buttonChangeUser->setObjectName(QString::fromUtf8("buttonChangeUser"));
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
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/resources/ChangeUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonChangeUser->setIcon(icon1);
        buttonChangeUser->setIconSize(QSize(32, 32));

        gridLayout->addWidget(buttonChangeUser, 5, 0, 1, 1);

        Window_Player->setCentralWidget(centralwidget);

        retranslateUi(Window_Player);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Window_Player);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Player)
    {
        Window_Player->setWindowTitle(QApplication::translate("Window_Player", "MainWindow", nullptr));
        buttonExit->setText(QApplication::translate("Window_Player", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        photo->setText(QString());
        fullNamePlayer->setText(QApplication::translate("Window_Player", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\230.", nullptr));
        balance->setText(QApplication::translate("Window_Player", "\320\221\320\260\320\273\320\260\320\275\321\201", nullptr));
        label->setText(QString());
        replenish->setText(QApplication::translate("Window_Player", "\320\237\320\276\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\201\321\207\321\221\321\202", nullptr));
        label_3->setText(QString());
        credits->setText(QApplication::translate("Window_Player", "\320\232\321\200\320\265\320\264\320\270\321\202\321\213", nullptr));
        gameTables->setText(QApplication::translate("Window_Player", "\320\230\320\263\321\200\320\276\320\262\321\213\320\265 \321\201\321\202\320\276\320\273\321\213", nullptr));
        label_2->setText(QString());
        buttonChangeUser->setText(QApplication::translate("Window_Player", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Player: public Ui_Window_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PLAYER_H
