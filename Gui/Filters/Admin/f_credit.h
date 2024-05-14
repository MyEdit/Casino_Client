#ifndef F_CREDIT_H
#define F_CREDIT_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_Credit;
}

class F_Credit : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_Credit *ui;

public:
    explicit F_Credit(QWidget *parent = nullptr);
    ~F_Credit();

private:
    void initFunSetFilters() override;
    void initFunButton() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_CREDIT_H
