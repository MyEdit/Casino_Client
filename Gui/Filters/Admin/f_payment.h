#ifndef F_PAYMENT_H
#define F_PAYMENT_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_Payment;
}

class F_Payment : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_Payment *ui;

public:
    explicit F_Payment(QWidget *parent = nullptr);
    ~F_Payment();

private:
    void initFunSetFilters() override;
    void initFunVisibletFilters() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_PAYMENT_H
