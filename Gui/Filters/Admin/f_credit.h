#ifndef F_CREDIT_H
#define F_CREDIT_H

#include <QDialog>

namespace Ui {
class F_Credit;
}

class F_Credit : public QDialog
{
    Q_OBJECT

public:
    explicit F_Credit(QWidget *parent = nullptr);
    ~F_Credit();

private:
    Ui::F_Credit *ui;
};

#endif // F_CREDIT_H
