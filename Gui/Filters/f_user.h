#ifndef F_USER_H
#define F_USER_H

#include <QDialog>

namespace Ui {
class F_User;
}

class F_User : public QDialog
{
    Q_OBJECT

public:
    explicit F_User(QWidget *parent = nullptr);
    ~F_User();

private:
    Ui::F_User *ui;
};

#endif // F_USER_H
