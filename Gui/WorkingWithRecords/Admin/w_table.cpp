#include "w_table.h"
#include "ui_w_table.h"

W_Table::W_Table(const QueryTypes actionType, QSharedPointer<ActiveTable> defaultActiveTable, QWidget *parent) :
    QWidget(parent), ui(new Ui::W_Table), actionType(actionType), defaultActiveTable(defaultActiveTable)
{
    ui->setupUi(this);
    loadComboBoxNameGame();
    onLoadForm();
    customizationLiteEdit();
}

W_Table::~W_Table()
{
    delete ui;
}

void W_Table::on_bottonSave_clicked()
{
    QSharedPointer<ActiveTable> activeTable = QSharedPointer<ActiveTable>::create(defaultActiveTable->getID(), getMaxPlayers(), defaultActiveTable->getNumPlayers(), getMinBet(), getBetStep(), getMinBalance(), getNameGame());
    QString query;

    if (!activeTable->inputDataIsValid())
    {
        NotificationUtil::viewNotification({TypeMessage::Error, "Заполнены не все поля"});
        return;
    }

    if (actionType == QueryTypes::CreateEntry)
        query = getInsertQuery(activeTable);
    else
        query = getUpdateQuery(activeTable);

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&actionType, sizeof(QueryTypes));
    NetworkClient::sendToServer(query);

    this->close();
}

const QString W_Table::getMaxPlayers()
{
    return ui->InputMaxPlayer->text();
}


const QString W_Table::getMinBet()
{
    return ui->InputMinBet->text();
}

const QString W_Table::getBetStep()
{
    return ui->InputBetStep->text();
}

const QString W_Table::getMinBalance()
{
    return ui->InputMinBalance->text();
}

const QString W_Table::getNameGame()
{
    return ui->nameGame->currentText();
}

void W_Table::loadComboBoxNameGame()
{
    //TODO: Нужно будет переделать на заполнение на основании загруженных плагинов
    ui->nameGame->addItem("Девятка");
    ui->nameGame->addItem("Блэкджек");
}

void W_Table::clearInput()
{
    for(QLineEdit* lineEdit : this->findChildren<QLineEdit*>())
    {
        lineEdit->clear();
    }
    ui->nameGame->setCurrentIndex(0);
}

void W_Table::setDefaultValues()
{
    ui->InputMaxPlayer->setText(defaultActiveTable->getMaxPlayers());
    ui->InputMinBet->setText(defaultActiveTable->getMinBet());
    ui->InputBetStep->setText(defaultActiveTable->getBetStep());
    ui->InputMinBalance->setText(defaultActiveTable->getMinBalance());
    ui->nameGame->setCurrentText(defaultActiveTable->getNameGame());
}

void W_Table::onLoadForm()
{
    switch (actionType)
    {
    case QueryTypes::CreateEntry:
    {
        connect(ui->buttonReset, &QPushButton::clicked, this, &W_Table::clearInput);
        setWindowTitle("Добавление стола");
        break;
    }
    case QueryTypes::UpdateEntry:
    {
        connect(ui->buttonReset, &QPushButton::clicked, this, &W_Table::setDefaultValues);
        setWindowTitle("Редактирование стола");
        setDefaultValues();
        break;
    }
    default:
        this->close();
    };
}

const QString W_Table::getInsertQuery(QSharedPointer<ActiveTable> activeTable)
{
    return QString("INSERT INTO ActiveTables (MaxPlayers, NumPlayers, MinBet, BetStep, MinBalance, NameGame) VALUES ('%1', '%2', '%3', '%4', '%5', '%6')")
            .arg(activeTable->getMaxPlayers())
            .arg("0")
            .arg(activeTable->getMinBet())
            .arg(activeTable->getBetStep())
            .arg(activeTable->getMinBalance())
            .arg(activeTable->getNameGame());
}

const QString W_Table::getUpdateQuery(QSharedPointer<ActiveTable> activeTable)
{
    return QString("UPDATE ActiveTables SET MaxPlayers = '%1', NumPlayers = '%2', MinBet = '%3', BetStep = '%4', MinBalance = '%5', NameGame = '%6' WHERE ID_Table = '%7'")
            .arg(activeTable->getMaxPlayers())
            .arg(activeTable->getNumPlayers())
            .arg(activeTable->getMinBet())
            .arg(activeTable->getBetStep())
            .arg(activeTable->getMinBalance())
            .arg(activeTable->getNameGame())
            .arg(activeTable->getID());
}

void W_Table::customizationLiteEdit()
{
    ui->InputMaxPlayer->setValidator(new QIntValidator(this)); //ввот только цифр
    ui->InputMinBet->setValidator(new QIntValidator(this));
    ui->InputBetStep->setValidator(new QIntValidator(this));
    ui->InputMinBalance->setValidator(new QIntValidator(this));
}
