#ifndef ADD_TABLE_H
#define ADD_TABLE_H

#include <QWidget>

namespace Ui {
class Add_Table;
}

class Add_Table : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Table(QWidget *parent = nullptr);
    ~Add_Table();

private:
    Ui::Add_Table *ui;
};

#endif // ADD_TABLE_H
