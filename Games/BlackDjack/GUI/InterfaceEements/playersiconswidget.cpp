#include "playersiconswidget.h"
#include "ui_playersiconswidget.h"

PlayersIconsWidget::PlayersIconsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayersIconsWidget)
{
    ui->setupUi(this);
}

PlayersIconsWidget::~PlayersIconsWidget()
{
    delete ui;
}
