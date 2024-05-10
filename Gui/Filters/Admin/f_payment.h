#ifndef F_PAYMENT_H
#define F_PAYMENT_H

#include <QDialog>

namespace Ui {
class F_Payment;
}

class F_Payment : public QDialog
{
    Q_OBJECT

public:
    explicit F_Payment(QWidget *parent = nullptr);
    ~F_Payment();

private:
    Ui::F_Payment *ui;
};

#endif // F_PAYMENT_H
