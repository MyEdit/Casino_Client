#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPainter>
#include "Gui/Notification/notification.h"
#include "Games/Tabel/table.h"
#include "Utils/windowtracker.h"

namespace Ui {
class Form;
}

class Table;

class Form : public QWidget
{
    Q_OBJECT
    Ui::Form *ui;
    QSharedPointer<Table> table;
    QString constantStyleSheet;
    QString hoverStyleSheet;
    QString pressStyleSheet;
    bool canJoin;

public:
    explicit Form(QSharedPointer<Table> table, QWidget *parent = nullptr);
    ~Form();

    QSharedPointer<Table> getTable() const;
    void update();

private:
    void assigningValues();
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void settingInformation();
};

#endif // FORM_H
