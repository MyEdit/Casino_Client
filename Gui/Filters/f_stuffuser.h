#ifndef F_STUFFUSER_H
#define F_STUFFUSER_H

#include <QDialog>

namespace Ui {
class F_StuffUser;
}

class F_StuffUser : public QDialog
{
    Q_OBJECT

public:
    explicit F_StuffUser(QWidget *parent = nullptr);
    ~F_StuffUser();

private:
    Ui::F_StuffUser *ui;
};

#endif // F_STUFFUSER_H
