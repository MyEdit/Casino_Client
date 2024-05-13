#ifndef F_USER_H
#define F_USER_H

#include "BaseClass/baseclasfilter.h"

namespace Ui {
class F_User;
}

class F_User : public BaseClasFilter
{
    Q_OBJECT
    Ui::F_User *ui;

public:
    explicit F_User(QWidget *parent = nullptr);
    ~F_User();

private:
    void initFunSetFilters() override;
    void initFunVisibletFilters() override;
    void hideCategory() override;
    void customizationLiteEdit() override;
};

#endif // F_USER_H
