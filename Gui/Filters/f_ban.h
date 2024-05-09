#ifndef F_BAN_H
#define F_BAN_H

#include <QDialog>

namespace Ui {
class F_Ban;
}

class F_Ban : public QDialog
{
    Q_OBJECT

public:
    explicit F_Ban(QWidget *parent = nullptr);
    ~F_Ban();

private:
    Ui::F_Ban *ui;
};

#endif // F_BAN_H
