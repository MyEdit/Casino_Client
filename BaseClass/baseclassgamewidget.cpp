#include "baseclassgamewidget.h"


void BaseClassGameWidget::updatePlayersIcons(QList<QSharedPointer<Player> > playes)
{
    playersIcons->fullClearInfo();

    playersIcons->addPlayer(P_Authorization::getPlayer());

    for(QSharedPointer<Player> player : playes)
    {
        if(player->getLogin() != P_Authorization::getPlayer()->getLogin())
            playersIcons->addPlayer(player);
    }
}

void BaseClassGameWidget::setMyScore(int score)
{
    playersIcons->setMyScore(score);
}

void BaseClassGameWidget::takeCard()
{
    P_Authorization::getPlayer()->getGame()->takeCard();
}

void BaseClassGameWidget::pass()
{
    P_Authorization::getPlayer()->getGame()->pass();
}

void BaseClassGameWidget::startChekedTable()
{
    timerCheckTable = new QTimer(this);

    connect(NetworkClient::packetHandler, &PacketHandler::signalSetQueryModel, this, &BaseClassGameWidget::distributor);

    connect(timerCheckTable, &QTimer::timeout, this, &BaseClassGameWidget::checkTableExistence);

    timerCheckTable->start(1000);
}

void BaseClassGameWidget::changeEvent(QEvent* event)
{
    QWidget::changeEvent(event);
    WindowTracker::activeWindow = this;
}

void BaseClassGameWidget::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
    startChekedTable();
}

void BaseClassGameWidget::closeEvent(QCloseEvent* event)
{
    QWidget::closeEvent(event);
    timerCheckTable->stop();
    P_Authorization::getPlayer()->clearCardsInHand();
    P_Authorization::getPlayer()->getGame()->leave();
}

void BaseClassGameWidget::unlockInterface(const QString &nickname)
{
    updateProcessing(nickname);
    blocingInterface(true);
}

void BaseClassGameWidget::finished(bool isWin)
{
    if(isWin)
        Notification::showNotification(TypeMessage::Information, "Победа");
    else
        Notification::showNotification(TypeMessage::Error, "Проигрыш");
}

void BaseClassGameWidget::checkTableExistence()
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

void BaseClassGameWidget::distributor(QSharedPointer<QueryData> data)
{
    if(data->modelTypes != model)
        return;

    if(data->result == "0")
        close();
}

void BaseClassGameWidget::insufficientBalance()
{
    close();
    Notification::showNotification(TypeMessage::Error, "У вас недостаточный баланс для продолжения");
}
