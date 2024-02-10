#ifndef ALLUSERS_H
#define ALLUSERS_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui {
class AllUsers;
}

class AllUsers : public QWidget
{
    Q_OBJECT
    Ui::AllUsers *ui;

public:
    explicit AllUsers(QWidget *parent = nullptr);
    ~AllUsers();

    void setModel(QStandardItemModel* model);
};

#endif // ALLUSERS_H
