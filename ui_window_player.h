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
    QLabel *photo;
    QVBoxLayout *verticalLayout_5;
    QLabel *FIO_employee_5;
    QLabel *post_5;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_7;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_25;
    QPushButton *banList_5;
    QLabel *label_26;
    QPushButton *stuffUsers_5;
    QPushButton *credits_5;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *users_5;
    QLabel *label_29;
    QPushButton *activeTables_5;
    QPushButton *payments_5;
    QLabel *label_30;
    QPushButton *buttonExit;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *Window_Player)
    {
        if (Window_Player->objectName().isEmpty())
            Window_Player->setObjectName(QString::fromUtf8("Window_Player"));
        Window_Player->resize(1064, 712);
        centralwidget = new QWidget(Window_Player);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background-color: rgb(51, 41, 123);\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        photo = new QLabel(centralwidget);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(65, 65));
        photo->setMaximumSize(QSize(65, 65));

        gridLayout->addWidget(photo, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(5, -1, 5, -1);
        FIO_employee_5 = new QLabel(centralwidget);
        FIO_employee_5->setObjectName(QString::fromUtf8("FIO_employee_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        FIO_employee_5->setFont(font);
        FIO_employee_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));
        FIO_employee_5->setWordWrap(true);

        verticalLayout_5->addWidget(FIO_employee_5);

        post_5 = new QLabel(centralwidget);
        post_5->setObjectName(QString::fromUtf8("post_5"));
        post_5->setFont(font);
        post_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        verticalLayout_5->addWidget(post_5);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(0);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_25->setScaledContents(true);

        gridLayout_7->addWidget(label_25, 4, 2, 1, 1);

        banList_5 = new QPushButton(centralwidget);
        banList_5->setObjectName(QString::fromUtf8("banList_5"));
        banList_5->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        banList_5->setFont(font1);
        banList_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_7->addWidget(banList_5, 3, 1, 1, 1);

        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_26->setScaledContents(true);

        gridLayout_7->addWidget(label_26, 2, 2, 1, 1);

        stuffUsers_5 = new QPushButton(centralwidget);
        stuffUsers_5->setObjectName(QString::fromUtf8("stuffUsers_5"));
        stuffUsers_5->setMinimumSize(QSize(0, 40));
        stuffUsers_5->setFont(font1);
        stuffUsers_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_7->addWidget(stuffUsers_5, 2, 1, 1, 1);

        credits_5 = new QPushButton(centralwidget);
        credits_5->setObjectName(QString::fromUtf8("credits_5"));
        credits_5->setMinimumSize(QSize(0, 40));
        credits_5->setFont(font1);
        credits_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_7->addWidget(credits_5, 4, 1, 1, 1);

        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_27->setScaledContents(true);

        gridLayout_7->addWidget(label_27, 3, 2, 1, 1);

        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_28->setScaledContents(true);

        gridLayout_7->addWidget(label_28, 1, 2, 1, 1);

        users_5 = new QPushButton(centralwidget);
        users_5->setObjectName(QString::fromUtf8("users_5"));
        users_5->setMinimumSize(QSize(0, 40));
        users_5->setFont(font1);
        users_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_7->addWidget(users_5, 1, 1, 1, 1);

        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setEnabled(true);
        label_29->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_29->setScaledContents(true);

        gridLayout_7->addWidget(label_29, 0, 2, 1, 1);

        activeTables_5 = new QPushButton(centralwidget);
        activeTables_5->setObjectName(QString::fromUtf8("activeTables_5"));
        activeTables_5->setMinimumSize(QSize(0, 40));
        activeTables_5->setFont(font1);
        activeTables_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_7->addWidget(activeTables_5, 0, 1, 1, 1);

        payments_5 = new QPushButton(centralwidget);
        payments_5->setObjectName(QString::fromUtf8("payments_5"));
        payments_5->setMinimumSize(QSize(0, 40));
        payments_5->setFont(font1);
        payments_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_7->addWidget(payments_5, 5, 1, 1, 1);

        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));
        label_30->setScaledContents(true);

        gridLayout_7->addWidget(label_30, 5, 2, 1, 1);


        gridLayout->addLayout(gridLayout_7, 2, 0, 1, 2);

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

        gridLayout->addWidget(buttonExit, 4, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(250, 97, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 2);

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

        gridLayout->addWidget(tabWidget, 0, 2, 5, 1);

        Window_Player->setCentralWidget(centralwidget);

        retranslateUi(Window_Player);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Window_Player);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Player)
    {
        Window_Player->setWindowTitle(QApplication::translate("Window_Player", "MainWindow", nullptr));
        photo->setText(QApplication::translate("Window_Player", "\320\244\320\276\321\202\320\276", nullptr));
        FIO_employee_5->setText(QApplication::translate("Window_Player", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\230.", nullptr));
        post_5->setText(QApplication::translate("Window_Player", "\320\221\320\260\320\273\320\260\320\275\321\201", nullptr));
        banList_5->setText(QApplication::translate("Window_Player", "\320\247\321\221\321\200\320\275\321\213\320\271 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        label_26->setText(QString());
        stuffUsers_5->setText(QApplication::translate("Window_Player", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        credits_5->setText(QApplication::translate("Window_Player", "\320\227\320\260\321\217\320\262\320\272\320\270 \320\275\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\321\213", nullptr));
        label_27->setText(QString());
        label_28->setText(QString());
        users_5->setText(QApplication::translate("Window_Player", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        label_29->setText(QString());
        activeTables_5->setText(QApplication::translate("Window_Player", "\320\230\320\263\321\200\320\276\320\262\321\213\320\265 \321\201\321\202\320\276\320\273\321\213", nullptr));
        payments_5->setText(QApplication::translate("Window_Player", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \321\202\321\200\320\260\320\275\320\267\320\260\320\272\321\206\320\270\320\271", nullptr));
        label_30->setText(QString());
        buttonExit->setText(QApplication::translate("Window_Player", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Player: public Ui_Window_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PLAYER_H
