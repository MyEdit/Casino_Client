#ifndef F_PLAYERCREDIT_H
#define F_PLAYERCREDIT_H

#include <QDialog>

namespace Ui {
class F_PlayerCredit;
}

class F_PlayerCredit : public QDialog
{
    Q_OBJECT

public:
    explicit F_PlayerCredit(QWidget *parent = nullptr);
    ~F_PlayerCredit();

private:
    Ui::F_PlayerCredit *ui;
};

#endif // F_PLAYERCREDIT_H
