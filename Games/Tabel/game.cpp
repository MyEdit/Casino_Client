#include "game.h"

Game::Game()
{
    initPacketHandlerFunction();
}

Game::Game(const QString nameGame)
{
    this->nameGame = nameGame;
    initPacketHandlerFunction();
}

const QString& Game::getName()
{
    return nameGame;
}

QSharedPointer<BaseClassGameWidget> Game::getGUI()
{
    return GUI;
}

QSharedPointer<QByteArray> Game::serializeGame()
{
    QSharedPointer<QByteArray> data(new QByteArray());
    QDataStream stream(&*data, QIODevice::WriteOnly);
    stream << nameGame;
    return data;
}

void Game::updatePlayersIcons(QList<QSharedPointer<Player> > players)
{
    emit signalUpdatePlayersIcons(players);
}

void Game::setGameName(const QString& nameGame)
{
    this->nameGame = nameGame;
}

void Game::setMenu(QWidget *menu)
{
    this->menu = menu;
}

void Game::takeCard()
{
    this->turn(GamePackets::P_TakeCard);
}

void Game::pass()
{
    this->turn(GamePackets::P_PassMove);
    emit signalBlocingInterface(false);
}

void Game::setConnects()
{
    QObject::connect(this, &Game::signalStartMove, GUI.get(), &BaseClassGameWidget::unlockInterface);
    QObject::connect(this, &Game::signalTakeCard, GUI.get(), &BaseClassGameWidget::renderTakeCard);
    QObject::connect(this, &Game::signalTakeCardAnotherPlayer, GUI.get(), &BaseClassGameWidget::renderFakeTakeCard);
    QObject::connect(this, &Game::signalUpdateTimer, GUI.get(), &BaseClassGameWidget::updateTimer);
    QObject::connect(this, &Game::signalUpdateProcessing, GUI.get(), &BaseClassGameWidget::updateProcessing);
    QObject::connect(this, &Game::signalBlocingInterface, GUI.get(), &BaseClassGameWidget::blocingInterface);
    QObject::connect(this, &Game::signalUpdatePlayersIcons, GUI.get(), &BaseClassGameWidget::updatePlayersIcons);
    QObject::connect(this, &Game::signalClearCardOnTable, GUI.get(), &BaseClassGameWidget::clearCardOnTable);
    QObject::connect(this, &Game::signalFinished, GUI.get(), &BaseClassGameWidget::finished);
    QObject::connect(this, &Game::signalInsufficientBalance, GUI.get(), &BaseClassGameWidget::insufficientBalance);
}

void Game::onTakeCard()
{
    CardRank cardRank = NetworkClient::getMessageFromServer<CardRank>();
    CardSuit cardSuit = NetworkClient::getMessageFromServer<CardSuit>();
    renderTakeCard(QSharedPointer<Card>(new Card(cardRank, cardSuit)));
}

void Game::leave()
{
    PacketTypes packettype = PacketTypes::P_PlayerLeaveTable;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));

    if(menu)
        menu->setEnabled(true);

    if (P_Authorization::playerW)
        P_Authorization::playerW->getGameTabelsLoading()->start();
}

int Game::getTableID()
{
    return idTable;
}

void Game::onGameFinished(bool isWin)
{
    QSharedPointer<Player> player = P_Authorization::getPlayer();
    emit signalFinished(isWin);

    emit signalClearCardOnTable();
    player->clearCardsInHand();

    if (player->getBalance() < Table::getTable(idTable)->getSettings().minBalance)
        emit signalInsufficientBalance();
}

void Game::renderTakeCard(QSharedPointer<Card> card)
{
    P_Authorization::getPlayer()->addCardInHand(card);
    emit signalTakeCard(card);
}

void Game::renderTakeCardAnotherPlayer(const QString &nicname)
{
    emit signalTakeCardAnotherPlayer(nicname);
}

void Game::turn(Game::GamePackets gamePacket)
{
    PacketTypes packettype = PacketTypes::P_GamePacket;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));
    NetworkClient::sendToServer(&gamePacket, sizeof(GamePackets));
}

void Game::onTakeCardAnotherPlayer()
{
    QString nicname = NetworkClient::getMessageFromServer();
    renderTakeCardAnotherPlayer(nicname);
}

void Game::onStartMove()
{
    emit signalStartMove(NetworkClient::getMessageFromServer());
}

void Game::onUpdateGameProcessing(const QString &data)
{
    bool ok;
    data.toInt(&ok);
    if(ok)
        emit signalUpdateTimer(data);
    else
        emit signalUpdateProcessing(data);
}

void Game::createGUI()
{
    setConnects();
}

void Game::onGamePacketReceived()
{
    GamePackets gamePacket = NetworkClient::getMessageFromServer<GamePackets>();

    if(gamePacketFunction.contains(gamePacket))
        gamePacketFunction[gamePacket]();
    else
        Message::logWarn("[" + getName() + "] Server send unknown game packet");
}

void Game::initPacketHandlerFunction()
{
    gamePacketFunction =
    {
        {GamePackets::P_TakeCard,               [&]() {this->onTakeCard();}},
        {GamePackets::P_TakeCardAnotherPlayer,  [&]() {this->onTakeCardAnotherPlayer();}},
        {GamePackets::P_StartMove,              [&]() {this->onStartMove();}},
        {GamePackets::P_Win,                    [&]() {this->onGameFinished(true);}},
        {GamePackets::P_Lose,                   [&]() {this->onGameFinished(false);}},
    };
}
