#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <QWidget>
#include <QScrollArea>
#include "Games/Tabel/table.h"
#include "Gui/form.h"
#include "Network/networkclient.h"

class Form;

namespace Ui {
class GameTable;
}

class GameTable : public QWidget
{
    Q_OBJECT
    Ui::GameTable *ui;
    QSharedPointer<QTimer> timer;

public:
    explicit GameTable(QWidget *parent = nullptr);
    ~GameTable();

    void updateTables();
    void stop();
    void start();

private:
    void requestTables();
    void deleteOldTable(QList<Form*>& forms);
    void renderNewTable(QList<Form*>& forms);
};

#endif // GAMETABLE_H
