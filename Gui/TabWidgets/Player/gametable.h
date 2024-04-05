#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QWidget>
#include <QScrollArea>
#include "Games/Tabel/table.h"
#include "Gui/form.h"

namespace Ui {
class GameTable;
}

class GameTable : public QWidget
{
    Q_OBJECT

public:
    explicit GameTable(QWidget *parent = nullptr);
    ~GameTable();

    void updateTables();

private:
    Ui::GameTable *ui;
};

#endif // GAMETABLE_H
