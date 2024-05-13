#ifndef F_PLAYERCREDIT_H
#define F_PLAYERCREDIT_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_PlayerCredit;
}

class F_PlayerCredit : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_PlayerCredit *ui;

public:
    explicit F_PlayerCredit(QWidget *parent = nullptr);
    ~F_PlayerCredit();

private:
    void initFunSetFilters() override;
    void initFunVisibletFilters() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_PLAYERCREDIT_H
