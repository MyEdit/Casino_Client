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
    void initFunSetFilters();
    void initFunVisibletFilters();
    void hideCategory();
    void customizationLiteEdit();
};

#endif // F_TABLE_H
