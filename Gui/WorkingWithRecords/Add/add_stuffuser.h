#ifndef ADD_STUFFUSER_H
#define ADD_STUFFUSER_H

#include <QWidget>

namespace Ui {
class Add_StuffUser;
}

class Add_StuffUser : public QWidget
{
    Q_OBJECT

public:
    explicit Add_StuffUser(QWidget *parent = nullptr);
    ~Add_StuffUser();

private:
    Ui::Add_StuffUser *ui;
};

#endif // ADD_STUFFUSER_H
