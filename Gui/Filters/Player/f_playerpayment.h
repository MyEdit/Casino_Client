#ifndef F_PLAYERPAYMENT_H
#define F_PLAYERPAYMENT_H

#include <QDialog>

namespace Ui {
class F_PlayerPayment;
}

class F_PlayerPayment : public QDialog
{
    Q_OBJECT

public:
    explicit F_PlayerPayment(QWidget *parent = nullptr);
    ~F_PlayerPayment();

private:
    Ui::F_PlayerPayment *ui;
};

#endif // F_PLAYERPAYMENT_H
