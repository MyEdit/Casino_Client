#include "form.h"
#include "ui_form.h"

Form::Form(QSharedPointer<Table> table, QWidget *parent) : QWidget(parent), ui(new Ui::Form), table(table)
{
    ui->setupUi(this);
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
    ui->name->setText(table->getGame()->getName());
    ui->minBet->setText(QString::number(table->getSettings().minBet));
    ui->betStep->setText(QString::number(table->getSettings().stepBet));
    ui->minBalance->setText(QString::number(table->getSettings().minBalance));
    ui->currentNumPlayer->setText(QString::number(table->getCurrentNumPlayer()));
    ui->maxNumPlayer->setText(QString::number(table->getSettings().maxCountPlayers));
}

void Form::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    setStyleSheet(pressStyleSheet);

    if (!this->table->canJoin())
    {
        Notification* message = new Notification();
        message->setAlertProperties(TypeMessage::Warning, "Вы не можете присоединиться к этой игре", WindowTracker::activeWindow);
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
    constantStyleSheet = "#Form{background-color: rgb(170, 170, 255);}";
    hoverStyleSheet = "#Form{background-color: rgb(100, 100, 255);}";
    pressStyleSheet = "#Form{background-color: rgb(50, 50, 255);}";
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
