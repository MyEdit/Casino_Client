#include "table.h"

QList<QSharedPointer<Table>> Table::tables;

Table::Table(Game game, TableSettings tableSettings)
{
    this->game = game;
    this->tableSettings = tableSettings;
}

Table::Table(Game game, TableSettings tableSettings, int currentNumPlayer)
{
    this->game = game;
    this->tableSettings = tableSettings;
    this->currentNumPlayer = currentNumPlayer;
}

void Table::addTables(QSharedPointer<Table> table)
{
    if(!tables.contains(table))
        tables.append(table);
}

QByteArray Table::serializeTable()
{
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    QByteArray gameData = game.serializeGame();
    QByteArray settingsData = tableSettings.serializeTableSettings();
    stream << gameData << settingsData;
    return data;
}

QSharedPointer<Table> Table::deserializeTable(const QByteArray& data)
{
    QDataStream stream(data);
    QByteArray gameData, settingsData;
    int currentNumPlayer;
    stream >> gameData >> settingsData >> currentNumPlayer;
    QSharedPointer<Game> game = Game::deserializeGame(gameData);
    TableSettings settings = TableSettings::deserializeTableSettings(settingsData);
    return QSharedPointer<Table>(new Table(*game.get(), settings, currentNumPlayer));
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
    return  currentNumPlayer;
}
