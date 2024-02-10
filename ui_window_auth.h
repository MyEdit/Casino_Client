/********************************************************************************
** Form generated from reading UI file 'window_auth.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_AUTH_H
#define UI_WINDOW_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Auth
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QLineEdit *textBox_Login;
    QLineEdit *textBox_Password;
    QPushButton *Button_Auth;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *Window_Auth)
    {
        if (Window_Auth->objectName().isEmpty())
            Window_Auth->setObjectName(QString::fromUtf8("Window_Auth"));
        Window_Auth->resize(665, 350);
        Window_Auth->setDocumentMode(false);
        centralwidget = new QWidget(Window_Auth);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, -1, 0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(400, 350));
        label->setPixmap(QPixmap(QString::fromUtf8(":/photos/resources/Window_Auth_Background.png")));
        label->setScaledContents(true);
        label->setWordWrap(false);

        gridLayout->addWidget(label, 0, 0, 5, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        textBox_Login = new QLineEdit(centralwidget);
        textBox_Login->setObjectName(QString::fromUtf8("textBox_Login"));
        textBox_Login->setMinimumSize(QSize(250, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        textBox_Login->setFont(font);

        gridLayout->addWidget(textBox_Login, 1, 1, 1, 1);

        textBox_Password = new QLineEdit(centralwidget);
        textBox_Password->setObjectName(QString::fromUtf8("textBox_Password"));
        textBox_Password->setMinimumSize(QSize(250, 50));
        textBox_Password->setFont(font);

        gridLayout->addWidget(textBox_Password, 2, 1, 1, 1);

        Button_Auth = new QPushButton(centralwidget);
        Button_Auth->setObjectName(QString::fromUtf8("Button_Auth"));
        Button_Auth->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(Button_Auth, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        Window_Auth->setCentralWidget(centralwidget);

        retranslateUi(Window_Auth);

        QMetaObject::connectSlotsByName(Window_Auth);
    } // setupUi

    void retranslateUi(QMainWindow *Window_Auth)
    {
        Window_Auth->setWindowTitle(QApplication::translate("Window_Auth", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QString());
        textBox_Login->setPlaceholderText(QApplication::translate("Window_Auth", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
        textBox_Password->setPlaceholderText(QApplication::translate("Window_Auth", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        Button_Auth->setText(QApplication::translate("Window_Auth", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window_Auth: public Ui_Window_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_AUTH_H
