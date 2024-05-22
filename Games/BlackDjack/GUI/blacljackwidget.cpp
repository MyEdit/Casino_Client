#include "blacljackwidget.h"
#include "ui_blacljackwidget.h"

BlaclJackWidget::BlaclJackWidget(QWidget *parent) :
    BaseClassGameWidget(parent),
    ui(new Ui::BlaclJackWidget)
{
    ui->setupUi(this);
    model = ModelTypes::ActiveTables;
    rendering();
    connects();
}

BlaclJackWidget::~BlaclJackWidget()
{
    delete timerCheckTable;
    delete ui;
}

void BlaclJackWidget::rendering()
{
    renderingTable();
    renderingPlayersIcons();

    blocingInterface(false);
}

void BlaclJackWidget::renderingTable()
{
    background = QSharedPointer<BlackJackBackground>(new BlackJackBackground());
    ui->gridLayout->addWidget(background.get(), 0, 0, Qt::AlignCenter);
}

void BlaclJackWidget::renderingPlayersIcons()
{
    playersIcons = QSharedPointer<PlayersIconsWidget>(new PlayersIconsWidget);
    ui->gridLayout->addWidget(playersIcons.get(), 0, 0);
}

void BlaclJackWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int w = width() / 10;
    int h = height() / 4;
    background->updateCardSize(w, h);
}

void BlaclJackWidget::renderTakeCard(QSharedPointer<Card> card)
{
    playersIcons->takenCard(P_Authorization::getPlayer()->getLogin());
    background->movingCard(card);
}

void BlaclJackWidget::renderFakeTakeCard(const QString& nickname)
{
    for(QSharedPointer<PlayerIcon> playersIcon : playersIcons->getPlayerIcons())
    {
        if(playersIcon->getPlayer()->getLogin() == nickname)
        {
            background->movingFaceCard(playersIcons->getRectPlayerIcon(playersIcon));
            playersIcon->takenCard();
        }
    }
}

void BlaclJackWidget::connects()
{
    connect(ui->buttonTakeCard, &QPushButton::clicked, this, &BlaclJackWidget::takeCard);
    connect(ui->buttonDoNotTakeCard, &QPushButton::clicked, this, &BlaclJackWidget::pass);
}

void BlaclJackWidget::clearCardOnTable()
{
    playersIcons->resetCountCard();
    background->clearTable();
}

void BlaclJackWidget::blocingInterface(const bool flag)
{
    ui->buttonTakeCard->setEnabled(flag);
    ui->buttonDoNotTakeCard->setEnabled(flag);
}

void BlaclJackWidget::finished(bool isWin)
{
    BaseClassGameWidget::finished(isWin);

    ui->labelGameProcess->setText("Ожидание");
}

void BlaclJackWidget::updateProcessing(const QString& data)
{
    QString processing = "Ход - " + data;
    ui->labelGameProcess->setText(processing);
    blocingInterface(false);
}

void BlaclJackWidget::updateTimer(const QString& time)
{
    QString processing{};

    if(time == "-1")
    {
        processing = "Ожидание минимального кол-ва игроков...";
        blocingInterface(false);
    }
    else
        processing = time;

    if(time == "0")
    {
        processing = "Игра началась";
        clearCardOnTable();
        setMyScore(0);
    }

    ui->labelGameProcess->setText(processing);
}
