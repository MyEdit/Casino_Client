#ifndef F_PLAYERPAYMENT_H
#define F_PLAYERPAYMENT_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_PlayerPayment;
}

class F_PlayerPayment : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_PlayerPayment *ui;

public:
    explicit F_PlayerPayment(QWidget *parent = nullptr);
    ~F_PlayerPayment();

private:
    void initFunSetFilters() override;
    void initFunVisibletFilters() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_PLAYERPAYMENT_H
