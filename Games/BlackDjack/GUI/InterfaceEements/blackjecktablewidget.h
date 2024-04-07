#ifndef BLACKJECKTABLEWIDGET_H
#define BLACKJECKTABLEWIDGET_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class BlackJeckTableWidget;
}

class BlackJeckTableWidget : public QWidget
{
    Q_OBJECT
    Ui::BlackJeckTableWidget *ui;

public:
    explicit BlackJeckTableWidget(QWidget *parent = nullptr);
    ~BlackJeckTableWidget();

private:
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
};

#endif // BLACKJECKTABLEWIDGET_H
