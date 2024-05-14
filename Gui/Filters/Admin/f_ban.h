#ifndef F_BAN_H
#define F_BAN_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_Ban;
}

class F_Ban : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_Ban *ui;

public:
    explicit F_Ban(QWidget *parent = nullptr);
    ~F_Ban();

private:
    void initFunSetFilters() override;
    void initFunButton() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_BAN_H
