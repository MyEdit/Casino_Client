#ifndef ADD_BAN_H
#define ADD_BAN_H

#include <QWidget>

namespace Ui {
class Add_Ban;
}

class Add_Ban : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Ban(QWidget *parent = nullptr);
    ~Add_Ban();

private:
    Ui::Add_Ban *ui;
};

#endif // ADD_BAN_H
