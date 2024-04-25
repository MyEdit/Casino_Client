#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(const QString& user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome),
    _user(user)
{
    ui->setupUi(this);
    setTextToLabel();
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::setTextToLabel()
{
    QTime currentTime = QTime::currentTime();
    QString goodTime;

    int hour = currentTime.hour();

    if (hour >= 6 && hour < 12)
        goodTime = "Доброе утро, ";
    else if (hour >= 12 && hour < 17)
        goodTime = "Добрый день, ";
    else if (hour >= 17 && hour < 22)
        goodTime = "Добрый вечер, ";
    else
        goodTime = "Доброй ночи, ";

    ui->label->setText(goodTime + _user);
}
