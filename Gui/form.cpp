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

    updateTextIfDifferent(ui->name, table->getGame()->getName());
    updateTextIfDifferent(ui->minBet, QString::number(settings.minBet));
    updateTextIfDifferent(ui->betStep, QString::number(settings.stepBet));
    updateTextIfDifferent(ui->minBalance, QString::number(settings.minBalance));
    updateTextIfDifferent(ui->currentNumPlayer, QString::number(table->getCurrentNumPlayer()));
    updateTextIfDifferent(ui->maxNumPlayer, QString::number(settings.maxCountPlayers));
}

void Form::updateTextIfDifferent(QLabel* label, const QString& newText)
{
    if (label->text() != newText)
        label->setText(newText);
};

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
