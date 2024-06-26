﻿#ifndef F_PROFIT_H
#define F_PROFIT_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_Profit;
}

class F_Profit : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_Profit *ui;

public:
    explicit F_Profit(QWidget *parent = nullptr);
    ~F_Profit();

private:
    void initFunSetFilters() override;
    void initFunButton() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
    void connects() override;
    void specificDateChanged();
    void yourLimitsDateChanged();
};

#endif // F_PROFIT_H
