#ifndef F_TABLE_H
#define F_TABLE_H

#include <QDialog>

namespace Ui {
class F_Table;
}

class F_Table : public QDialog
{
    Q_OBJECT

public:
    explicit F_Table(QWidget *parent = nullptr);
    ~F_Table();

private:
    Ui::F_Table *ui;
};

#endif // F_TABLE_H
