#ifndef F_STUFFUSER_H
#define F_STUFFUSER_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_StuffUser;
}

class F_StuffUser : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_StuffUser *ui;

public:
    explicit F_StuffUser(QWidget *parent = nullptr);
    ~F_StuffUser();

private:
    void initFunSetFilters() override;
    void initFunButton() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_STUFFUSER_H
