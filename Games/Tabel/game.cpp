#include "game.h"


Game::Game(const QString nameGame)
{
    this->nameGame = nameGame;
    initPacketHandlerFunction();
}

const QString& Game::getName()
{
    return nameGame;
}

BaseClassGameWidget *Game::getGUI()
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
    GUI->updatePlayersIcons(players);
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
    GUI->blocingInterface(false);
}

void Game::pass()
{
    this->turn(GamePackets::P_PassMove);
    GUI->blocingInterface(false);
}

void Game::setConnects()
{
    QObject::connect(this, &Game::signalTakeCard, this, &Game::renderTakeCard);
    QObject::connect(this, &Game::signalTakeCardAnotherPlayer, this, &Game::renderTakeCardAnotherPlayer);
    QObject::connect(this, &Game::signalStartMove, this, &Game::unlockInterface);
}

void Game::onTakeCard()
{
    CardRank cardRank = NetworkClient::getMessageFromServer<CardRank>();
    CardSuit cardSuit = NetworkClient::getMessageFromServer<CardSuit>();
    emit signalTakeCard(QSharedPointer<Card>(new Card(cardRank, cardSuit)));
}

void Game::leave()
{
    PacketTypes packettype = PacketTypes::P_PlayerLeaveTable;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&idTable, sizeof(int));

    if(menu)
        menu->setEnabled(true);
}

void Game::onUpdateGameTimer(const QString &data)
{
    GUI->updateTimer(data);
}

int Game::getTableID()
{
    return idTable;
}

void Game::onGameFinished(bool isWin)
{
    QSharedPointer<Player> player = P_Authorization::getPlayer();
    QMetaObject::invokeMethod(GUI, "finished", Qt::QueuedConnection, Q_ARG(bool, isWin));

    GUI->clearCardOnTable();
    player->clearCardsInHand();

    if (player->getBalance() < Table::getTable(idTable)->getSettings().minBalance)
        QMetaObject::invokeMethod(GUI, "insufficientBalance", Qt::QueuedConnection);
}

void Game::renderTakeCard(QSharedPointer<Card> card)
{
    GUI->renderTakeCard(card);
    P_Authorization::getPlayer()->addCardInHand(card);
}

void Game::renderTakeCardAnotherPlayer(const QString &nicname)
{
    GUI->renderFakeTakeCard(nicname);
}

void Game::unlockInterface(const QString &nickname)
{
    P_Authorization::getPlayer()->getGame()->onUpdateGameProcessing(nickname);
    GUI->blocingInterface(true);
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
    emit signalTakeCardAnotherPlayer(NetworkClient::getMessageFromServer());
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
        onUpdateGameTimer(data);
    else
        GUI->updateProcessing(data);
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
