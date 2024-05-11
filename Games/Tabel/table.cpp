#include "table.h"
#include "Games/blackjack.h"

QList<QSharedPointer<Table>> Table::tables;
QMutex Table::accessTablesMutex;

Table::Table(QSharedPointer<Game> game, TableSettings tableSettings)
{
    this->game = game;
    this->tableSettings = tableSettings;
}

Table::Table(const QByteArray& data)
{
    QDataStream stream(data);
    QSharedPointer<QByteArray> gameData(new QByteArray());
    QSharedPointer<QByteArray> settingsData(new QByteArray());
    int currentNumPlayer;
    stream >> *gameData >> *settingsData >> currentNumPlayer;

    TableSettings settings = TableSettings::deserializeTableSettings(settingsData);
    QSharedPointer<BlackJack> blackJackGame(new BlackJack(settings.ID, gameData));

    for (int i = 0; i < currentNumPlayer; i++)
    {
        QByteArray playerData;
        stream >> playerData;
        QSharedPointer<Player> player(new Player(playerData));
        players.append(player);
    }

    this->game = blackJackGame;
    this->tableSettings = settings;
}

void Table::addTable(QSharedPointer<Table> table)
{
    QMutexLocker locker(&accessTablesMutex);
    if(!tables.contains(table))
        tables.append(table);
}

QSharedPointer<Table> Table::getTable(int ID)
{
    QMutexLocker locker(&accessTablesMutex);
    for (QSharedPointer<Table> table : tables)
    {
        if (table->getSettings().ID == ID)
        {
            return table;
        }
    }

    return nullptr;
}


QSharedPointer<QByteArray> Table::serializeTable()
{
    QSharedPointer<QByteArray> data(new QByteArray());
    QDataStream stream(&*data, QIODevice::WriteOnly);
    QSharedPointer<QByteArray> gameData = game->serializeGame();
    QSharedPointer<QByteArray> settingsData = tableSettings.serializeTableSettings();
    int currentNumPlayer = players.size();

    stream << *gameData << *settingsData << currentNumPlayer;

    for (QSharedPointer<Player> player : players)
    {
        QSharedPointer<QByteArray> playerData = player->serializeUser();
        stream << playerData;
    }

    return data;
}

bool Table::canJoin()
{
    if (isGameRunning)
        return false;

    if (P_Authorization::getPlayer()->getBalance() < this->tableSettings.minBalance)
        return false;

    if (this->players.size() >= this->tableSettings.maxCountPlayers)
        return false;

    return true;
}

void Table::tryJoin()
{
    PacketTypes packettype = PacketTypes::P_ConnectPlayerToTable;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&this->tableSettings.ID, sizeof(int));
}

QSharedPointer<Game> Table::getGame()
{
    return game;
}

TableSettings Table::getSettings()
{
    return tableSettings;
}

int Table::getCurrentNumPlayer()
{
    return  players.size();
}

void Table::openGameGUI()
{   
    game->setMenu(WindowTracker::activeWindow);
    WindowTracker::activeWindow->setEnabled(false);

    game->createGUI();
    game->getGUI()->updatePlayersIcons(players);
    game->getGUI()->show();

    P_Authorization::getPlayer()->setGame(game);
}

void Table::updatePlayers()
{
    game->updatePlayersIcons(players);
}

QList<QSharedPointer<Table>>& Table::getCopyListTabels()
{
    QMutexLocker locker(&accessTablesMutex);
    return tables;
}

QList<QSharedPointer<Table>>& Table::getTabels()
{
    QMutexLocker locker(&accessTablesMutex);
    return tables;
}

void Table::setNewData(TableSettings tableSettings, const QString& nameGame, QList<QSharedPointer<Player>> players)
{
    this->tableSettings = tableSettings;
    this->game->setGameName(nameGame);
    this->players = players;
}

QList<QSharedPointer<Player>> Table::getPlayers()
{
    return players;
}
