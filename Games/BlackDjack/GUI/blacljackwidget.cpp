#include "blacljackwidget.h"
#include "ui_blacljackwidget.h"

BlaclJackWidget::BlaclJackWidget(QSharedPointer<BlackJack> game, QWidget *parent) :
    BaseClassGameWidget(parent),
    ui(new Ui::BlaclJackWidget),
    game(game)
{
    ui->setupUi(this);
    rendering();
    connects();
}

BlaclJackWidget::~BlaclJackWidget()
{
    delete ui;
}

void BlaclJackWidget::rendering()
{
    renderingTable();
    renderingPlayersIcons();

    for (int i = 0; i < ui->horizontalLayout_2->count(); i++)
    {
        QWidget* widget = ui->horizontalLayout_2->itemAt(i)->widget();
        if (widget)
            widget->hide();
    }
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

    int w = width() / 1.3;
    int h = height() / 1.3;
    background->setFixedSize(w, h);
}

void BlaclJackWidget::renderTakeCard(QSharedPointer<Card> card)
{
    background->movingCard(card);
}

void BlaclJackWidget::renderFakeTakeCard(const QString& nicname)
{
    for(QSharedPointer<PlayerIcon> playersIcon : playersIcons->getPlayerIcons())
    {
        if(playersIcon->getPlayer()->getLogin() == nicname)
            background->movingFaceCard(playersIcons->getRectPlayerIcon(playersIcon));
    }
}

void BlaclJackWidget::updatePlayersIcons(QList<QSharedPointer<Player>> playes)
{
    playersIcons->fullClearInfo();

    playersIcons->addPlayer(P_Authorization::getPlayer());

    for(QSharedPointer<Player> player : playes)
    {
        if(player->getLogin() != P_Authorization::getPlayer()->getLogin())
            playersIcons->addPlayer(player);
    }
}

void BlaclJackWidget::connects()
{
    connect(ui->buttonTakeCard, &QPushButton::clicked, this, &BlaclJackWidget::takeCard);
    connect(ui->buttonDoNotTakeCard, &QPushButton::clicked, this, &BlaclJackWidget::pass);
}

void BlaclJackWidget::takeCard()
{
    game->takeCard();
}

void BlaclJackWidget::pass()
{
    game->pass();
}

void BlaclJackWidget::clearCardOnTable()
{
    background->clearTable();
}

void BlaclJackWidget::blocingInterface(const bool flag)
{
    ui->buttonTakeCard->setEnabled(flag);
    ui->buttonDoNotTakeCard->setEnabled(flag);
}

void BlaclJackWidget::changeEvent(QEvent *event)
{
    QWidget::changeEvent(event);
    WindowTracker::activeWindow = this;
}

void BlaclJackWidget::setMyScore(int score)
{
    playersIcons->setMyScore(score);
}

void BlaclJackWidget::finished(bool isWin)
{
    if(isWin)
        Notification::showNotification(TypeMessage::Information, "Победа");
    else
        Notification::showNotification(TypeMessage::Error, "Проигрыш");
}

void BlaclJackWidget::insufficientBalance()
{
    close();
    Notification::showNotification(TypeMessage::Error, "У вас недостаточный баланс для продолжения");
}

void BlaclJackWidget::closeEvent(QCloseEvent* event)
{
    QWidget::closeEvent(event);
    game->leave();
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
        for (int i = 0; i < ui->horizontalLayout_2->count(); i++)
        {
            QWidget* widget = ui->horizontalLayout_2->itemAt(i)->widget();
            if (widget)
                widget->show();
        }
        processing = "Игра началась";
        background->clearTable();
        setMyScore(0);
        blocingInterface(false);
    }

    ui->labelGameProcess->setText(processing);
}
