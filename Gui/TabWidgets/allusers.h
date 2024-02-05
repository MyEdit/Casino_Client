#ifndef ALLUSERS_H
#define ALLUSERS_H

#include <QWidget>

namespace Ui {
class AllUsers;
}

class AllUsers : public QWidget
{
    Q_OBJECT

public:
    explicit AllUsers(QWidget *parent = nullptr);
    ~AllUsers();

private:
    Ui::AllUsers *ui;
};

#endif // ALLUSERS_H
