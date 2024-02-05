#ifndef CREATEGAMETABLE_H
#define CREATEGAMETABLE_H

#include <QWidget>

namespace Ui {
class CreateGameTable;
}

class CreateGameTable : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGameTable(QWidget *parent = nullptr);
    ~CreateGameTable();

private:
    Ui::CreateGameTable *ui;
};

#endif // CREATEGAMETABLE_H
