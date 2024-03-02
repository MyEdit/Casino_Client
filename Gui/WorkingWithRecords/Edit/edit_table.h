#ifndef EDIT_TABLE_H
#define EDIT_TABLE_H

#include <QWidget>

namespace Ui {
class Edit_Table;
}

class Edit_Table : public QWidget
{
    Q_OBJECT

public:
    explicit Edit_Table(QWidget *parent = nullptr);
    ~Edit_Table();

private:
    Ui::Edit_Table *ui;
};

#endif // EDIT_TABLE_H
