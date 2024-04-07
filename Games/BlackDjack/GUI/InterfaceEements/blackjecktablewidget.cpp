#include "blackjecktablewidget.h"
#include "ui_blackjecktablewidget.h"

BlackJeckTableWidget::BlackJeckTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlackJeckTableWidget)
{
    ui->setupUi(this);
}

BlackJeckTableWidget::~BlackJeckTableWidget()
{
    delete ui;
}

void BlackJeckTableWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    int labelWidth = width() / 10;
    int labelHeight = height() / 4;

    QList<QLabel*> labels = findChildren<QLabel*>();
    for (QLabel* label : labels)
        label->setFixedSize(labelWidth, labelHeight);
}

void BlackJeckTableWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter( this );
    painter.drawPixmap( 0, 0, QPixmap(":/InterfaceEements/resources/Table.png").scaled(size()));

    QWidget::paintEvent(event);
}
