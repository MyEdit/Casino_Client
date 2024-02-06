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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Admin
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *buttonExit;
    QGridLayout *gridLayout_2;
    QLabel *post;
    QLabel *FIO_employee;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *plug;
    QGridLayout *gridLayout_3;
    QPushButton *buttonCreateTable;
    QLabel *label;
    QPushButton *buttonExistingTables;
    QLabel *label_2;
    QPushButton *buttonAllUsers;
    QLabel *label_3;

    void setupUi(QMainWindow *Window_Admin)
    {
        if (Window_Admin->objectName().isEmpty())
            Window_Admin->setObjectName(QString::fromUtf8("Window_Admin"));
        Window_Admin->resize(952, 567);
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
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
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
        buttonExit->setIconSize(QSize(24, 24));

        gridLayout->addWidget(buttonExit, 7, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        post = new QLabel(centralwidget);
        post->setObjectName(QString::fromUtf8("post"));
        post->setFont(font);
        post->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        gridLayout_2->addWidget(post, 1, 1, 1, 1);

        FIO_employee = new QLabel(centralwidget);
        FIO_employee->setObjectName(QString::fromUtf8("FIO_employee"));
        FIO_employee->setFont(font);
        FIO_employee->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"}"));

        gridLayout_2->addWidget(FIO_employee, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/photos/resources/TestStuffPhoto.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));

        gridLayout_2->addWidget(pushButton_2, 0, 0, 2, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

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

        gridLayout->addWidget(tabWidget, 0, 2, 9, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        plug = new QLabel(centralwidget);
        plug->setObjectName(QString::fromUtf8("plug"));

        gridLayout->addWidget(plug, 0, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        buttonCreateTable = new QPushButton(centralwidget);
        buttonCreateTable->setObjectName(QString::fromUtf8("buttonCreateTable"));
        buttonCreateTable->setMinimumSize(QSize(0, 40));
        buttonCreateTable->setFont(font);
        buttonCreateTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(255, 255, 255);\n"
"    border-top-left-radius: 10px;\n"
"    border-bottom-left-radius: 10px;\n"
"    color: rgb(51, 41, 123);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(buttonCreateTable, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        buttonExistingTables = new QPushButton(centralwidget);
        buttonExistingTables->setObjectName(QString::fromUtf8("buttonExistingTables"));
        buttonExistingTables->setMinimumSize(QSize(0, 40));
        buttonExistingTables->setFont(font);
        buttonExistingTables->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(buttonExistingTables, 1, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        buttonAllUsers = new QPushButton(centralwidget);
        buttonAllUsers->setObjectName(QString::fromUtf8("buttonAllUsers"));
        buttonAllUsers->setMinimumSize(QSize(0, 40));
        buttonAllUsers->setFont(font);
        buttonAllUsers->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background: transparent;\n"
"    border: none;\n"
"	color: rgb(255, 255, 255);\n"
"	padding: 5px;\n"
"	text-align: left;\n"
"}"));

        gridLayout_3->addWidget(buttonAllUsers, 2, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/recess.png")));

        gridLayout_3->addWidget(label_3, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 2, 0, 1, 2);

        Window_Admin->setCentralWidget(centralwidget);

        retranslateUi(Window_Admin);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Window_Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Admin)
    {
        Window_Admin->setWindowTitle(QApplication::translate("Window_Admin", "MainWindow", nullptr));
        buttonExit->setText(QApplication::translate("Window_Admin", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        post->setText(QApplication::translate("Window_Admin", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        FIO_employee->setText(QApplication::translate("Window_Admin", "\320\230\320\262\320\260\320\275\320\276\320\262 \320\230.\320\230.", nullptr));
        pushButton_2->setText(QString());
        plug->setText(QString());
#ifndef QT_NO_TOOLTIP
        buttonCreateTable->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        buttonCreateTable->setText(QApplication::translate("Window_Admin", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\321\202\320\276\320\273", nullptr));
        label->setText(QString());
        buttonExistingTables->setText(QApplication::translate("Window_Admin", "\320\241\320\276\320\267\320\264\320\260\320\275\320\275\321\213\320\265 \321\201\321\202\320\276\320\273\321\213", nullptr));
        label_2->setText(QString());
        buttonAllUsers->setText(QApplication::translate("Window_Admin", "\320\222\321\201\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\270", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Window_Admin: public Ui_Window_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ADMIN_H
