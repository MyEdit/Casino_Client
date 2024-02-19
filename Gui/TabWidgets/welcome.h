#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QTime>

namespace Ui {
class welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT
    Ui::welcome *ui;
    QString _user;

public:
    explicit Welcome(QString user, QWidget *parent = nullptr);
    ~Welcome();

private:
    void setTextToLabel();
};

#endif // WELCOME_H
