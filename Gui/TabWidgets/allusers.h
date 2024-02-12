#ifndef ALLUSERS_H
#define ALLUSERS_H

#include <QWidget>
#include "QStandardItemModel"
#include "Utils/Message.h"

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

private:
    void workingWithTableView();
};

#endif // ALLUSERS_H
