#ifndef F_TABLE_H
#define F_TABLE_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_Table;
}

class F_Table : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_Table *ui;

public:
    explicit F_Table(QWidget *parent = nullptr);
    ~F_Table();

private:
    void initFunSetFilters() override;
    void initFunVisibletFilters() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
    void connects() override;

    void textChangeMinBet();
};

#endif // F_TABLE_H
