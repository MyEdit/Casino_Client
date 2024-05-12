#ifndef F_TABLE_H
#define F_TABLE_H

#include <QDialog>
#include <QMap>
#include <QRadioButton>
#include <functional>
#include "Utils/Message.h"

namespace Ui {
class F_Table;
}

class F_Table : public QDialog
{
    Q_OBJECT
    Ui::F_Table *ui;
    QMap<QRadioButton*, std::function<void()>> functionsSetFilters;
    QMap<QPushButton*, std::function<void()>> functionsVisibleFilters;

public:
    explicit F_Table(QWidget *parent = nullptr);
    ~F_Table();

    void reset();

private:
    void connects();
    void applyFilter();
    void initFunSetFilters();
    void initFunVisibletFilters();
    void visibleCategory();
    void startSetting();
};

#endif // F_TABLE_H
