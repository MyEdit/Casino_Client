#include "blacljackwidget.h"
#include "ui_blacljackwidget.h"

BlaclJackWidget::BlaclJackWidget(QWidget *parent) :
    BaseClassGameWidget(parent),
    ui(new Ui::BlaclJackWidget)
{
    ui->setupUi(this);
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

    for (int i = 0; i < ui->horizontalLayout_2->count(); i++)
    {
        QWidget* widget = ui->horizontalLayout_2->itemAt(i)->widget();
        if (widget)
            widget->hide();
    }

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

    int w = width() / 1.3;
    int h = height() / 1.3;
    background->setFixedSize(w, h);
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
    P_Authorization::getPlayer()->getGame()->takeCard();
}

void BlaclJackWidget::pass()
{
    P_Authorization::getPlayer()->getGame()->pass();
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

void BlaclJackWidget::changeEvent(QEvent *event)
{
    QWidget::changeEvent(event);
    WindowTracker::activeWindow = this;
}

void BlaclJackWidget::setMyScore(int score)
{
    playersIcons->setMyScore(score);
}

void BlaclJackWidget::startChekedTable()
{
    timerCheckTable = new QTimer(this);

    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &BlaclJackWidget::distributor);

    connect(timerCheckTable, &QTimer::timeout, this, &BlaclJackWidget::checkTableExistence);

    timerCheckTable->start(1000);
}

void BlaclJackWidget::checkTableExistence()
{
    PacketTypes packettype = PacketTypes::P_Query;
    QueryTypes queryTypes = QueryTypes::Other;
    ModelTypes modelTypes = ModelTypes::ActiveTables;

    QString query = "SELECT COUNT(*) FROM ActiveTables WHERE ID_Table = '" + QString::number(P_Authorization::getPlayer()->getGame()->getTableID()) + "'";

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&queryTypes, sizeof(QueryTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(query);
}

void BlaclJackWidget::distributor(QSharedPointer<QueryData> data)
{
    if(data->modelTypes != ModelTypes::ActiveTables)
        return;

    if(data->result == "0")
        close();
}

void BlaclJackWidget::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
    startChekedTable();
}

void BlaclJackWidget::finished(bool isWin)
{
    if(isWin)
        Notification::showNotification(TypeMessage::Information, "Победа");
    else
        Notification::showNotification(TypeMessage::Error, "Проигрыш");

    ui->labelGameProcess->setText("Ожидание");
}

void BlaclJackWidget::insufficientBalance()
{
    close();
    Notification::showNotification(TypeMessage::Error, "У вас недостаточный баланс для продолжения");
}

void BlaclJackWidget::closeEvent(QCloseEvent* event)
{
    QWidget::closeEvent(event);
    timerCheckTable->stop();
    P_Authorization::getPlayer()->getGame()->leave();
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
        clearCardOnTable();
        setMyScore(0);
    }

    ui->labelGameProcess->setText(processing);
}
