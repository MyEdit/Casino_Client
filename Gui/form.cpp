#include "form.h"
#include "ui_form.h"

Form::Form(QSharedPointer<Table> table, QWidget *parent) : QWidget(parent), ui(new Ui::Form), table(table)
{
    ui->setupUi(this);
    canJoin = table->canJoin();
    settingInformation();
    assigningValues();
    setStyleSheet(constantStyleSheet);
}

Form::~Form()
{
    delete ui;
}

void Form::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(palette().window());
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(contentsRect(), 10, 10);
}

void Form::settingInformation()
{
    const TableSettings& settings = table->getSettings();

    if (ui->name->text() != table->getGame()->getName())
        ui->name->setText(table->getGame()->getName());

    if (ui->minBet->text() != QString::number(settings.minBet))
        ui->minBet->setText(QString::number(settings.minBet));

    if (ui->betStep->text() != QString::number(settings.stepBet))
        ui->betStep->setText(QString::number(settings.stepBet));

    if (ui->minBalance->text() != QString::number(settings.minBalance))
        ui->minBalance->setText(QString::number(settings.minBalance));

    if (ui->currentNumPlayer->text() != QString::number(table->getCurrentNumPlayer()))
        ui->currentNumPlayer->setText(QString::number(table->getCurrentNumPlayer()));

    if (ui->maxNumPlayer->text() != QString::number(settings.maxCountPlayers))
        ui->maxNumPlayer->setText(QString::number(settings.maxCountPlayers));
}

void Form::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    setStyleSheet(pressStyleSheet);

    if (!canJoin)
    {
        Notification::showNotification(TypeMessage::Warning, "Вы не можете присоединиться к этой игре");
        return;
    }
    this->table->tryJoin();
}

void Form::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mouseReleaseEvent(event);
    setStyleSheet(constantStyleSheet);
}

void Form::assigningValues()
{
    if(canJoin)
    {
        constantStyleSheet = "background-color: rgb(170, 170, 255);";
        hoverStyleSheet = "background-color: rgb(100, 100, 255);";
        pressStyleSheet = "background-color: rgb(50, 50, 255);";
    }
    else
    {
        constantStyleSheet = "background-color: rgb(167, 167, 167); color: white;";
        hoverStyleSheet = "background-color: rgb(167, 167, 167); color: white;";
        pressStyleSheet = "background-color: rgb(167, 167, 167); color: white;";
    }
}

void Form::enterEvent(QEvent* event)
{
    QWidget::enterEvent(event);
    setStyleSheet(hoverStyleSheet);
}

void Form::leaveEvent(QEvent* event)
{
    QWidget::leaveEvent(event);
    setStyleSheet(constantStyleSheet);
}

QSharedPointer<Table> Form::getTable() const
{
    return table;
}

void Form::update()
{
    if(canJoin != table->canJoin())
    {
        canJoin = table->canJoin();
        assigningValues();
        setStyleSheet(constantStyleSheet);
    }
    settingInformation();
}
