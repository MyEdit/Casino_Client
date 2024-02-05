#ifndef EXISTINGTABLES_H
#define EXISTINGTABLES_H

#include <QWidget>

namespace Ui {
class ExistingTables;
}

class ExistingTables : public QWidget
{
    Q_OBJECT

public:
    explicit ExistingTables(QWidget *parent = nullptr);
    ~ExistingTables();

private:
    Ui::ExistingTables *ui;
};

#endif // EXISTINGTABLES_H
