#include "table.h"

QList<QSharedPointer<Table>> Table::tables;
QMutex Table::accessTablesMutex;

Table::Table(Game game, TableSettings tableSettings)
{
    this->game = game;
    this->tableSettings = tableSettings;
}

Table::Table(const QByteArray& data)
{
    QDataStream stream(data);
    QByteArray gameData, settingsData;
    int currentNumPlayer;
    stream >> gameData >> settingsData >> currentNumPlayer;
    QSharedPointer<Game> game = Game::deserializeGame(gameData);
    TableSettings settings = TableSettings::deserializeTableSettings(settingsData);

    for (int i = 0; i < currentNumPlayer; ++i)
    {
        QByteArray playerData;
        stream >> playerData;
        QSharedPointer<Player> player(new Player(playerData));
        players.append(player);
    }

    this->game = *game.get();
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


QByteArray Table::serializeTable()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    QByteArray gameData = game.serializeGame();
    QByteArray settingsData = tableSettings.serializeTableSettings();
    int currentNumPlayer = players.size();

    stream << gameData << settingsData << currentNumPlayer;

    for (QSharedPointer<Player> player : players)
    {
        QByteArray playerData = player->serializeUser();
        stream << playerData;
    }

    return data;
}

bool Table::canJoin()
{
    if (P_Authorization::getPlayer()->getBalance() < this->tableSettings.minBalance)
        return false;

    //TODO: Проверять кол-во игроков которые уже за столом

    return true;
}

void Table::tryJoin()
{
    PacketTypes packettype = PacketTypes::P_ConnectPlayerToTable;
    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&this->tableSettings.ID, sizeof(int));
}

Game Table::getGame()
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
    game.getGUI(); //TODO: должен вернуть гуи игры

    //Для теста
    qDebug() << tableSettings.ID;
    BlaclJackWidget* gameTest = new BlaclJackWidget(QSharedPointer<Table>(this));
    gameTest->updatePlayersIcons(players);
    gameTest->show();
    P_Authorization::getPlayer()->setTableGUI(gameTest);
}

void Table::updatePlayers()
{
    P_Authorization::getPlayer()->getTableGUI()->updatePlayersIcons(players);
}

QList<QSharedPointer<Table>>& Table::getTabels()
{
    QMutexLocker locker(&accessTablesMutex);
    return tables;
}

void Table::setNewData(TableSettings tableSettings, Game game, QList<QSharedPointer<Player>> players)
{
    this->tableSettings = tableSettings;
    this->game = game;
    this->players = players;
}

QList<QSharedPointer<Player>> Table::getPlayers()
{
    return players;
}
