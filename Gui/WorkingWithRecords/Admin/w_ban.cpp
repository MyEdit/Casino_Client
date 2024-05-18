#include "w_ban.h"
#include "ui_w_ban.h"

W_Ban::W_Ban(const QueryTypes actionType, QSharedPointer<Ban> defaultBan, QWidget* parent) :
    QWidget(parent), ui(new Ui::W_Ban), actionType(actionType), defaultBan(defaultBan)
{
    ui->setupUi(this);
    onLoadForm();
    setAttribute(Qt::WA_ShowModal, true);
}

W_Ban::~W_Ban()
{
    delete ui;
}

void W_Ban::on_buttonSave_clicked()
{
    QSharedPointer<Ban> ban = QSharedPointer<Ban>::create(defaultBan->getID(), defaultBan->getFullName(), getReason());
    QString query;

    if (!ban->inputDataIsValid())
    {
                Notification::showNotification(TypeMessage::Error, "Заполнены не все поля");
        return;
    }

    if (actionType == QueryTypes::CreateEntry)
        query = getInsertQuery(ban);
    else
        query = getUpdateQuery(ban);

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(&actionType, sizeof(QueryTypes));
    NetworkClient::sendToServer(query);

    this->close();
}

const QString W_Ban::getReason()
{
    return ui->InputReason->toPlainText();
}

void W_Ban::clearInput()
{
    ui->InputReason->clear();
}

void W_Ban::setDefaultValues()
{
    ui->name->setText(defaultBan->getFullName());
    ui->InputReason->setText(defaultBan->getReason());
}

void W_Ban::onLoadForm()
{
    switch (actionType)
    {
        case QueryTypes::CreateEntry:
        {
            connect(ui->buttonReset, &QPushButton::clicked, this, &W_Ban::clearInput);
            setWindowTitle("Блокировка пользователя");
            ui->name->setText(defaultBan->getFullName());
            break;
        }
        case QueryTypes::UpdateEntry:
        {
            connect(ui->buttonReset, &QPushButton::clicked, this, &W_Ban::setDefaultValues);
            setWindowTitle("Редактирование причины блокировки");
            setDefaultValues();
            break;
        }
        default:
            this->close();
    };
}

const QString W_Ban::getInsertQuery(QSharedPointer<Ban> ban)
{
    return QString("INSERT INTO Banlist (ID_User, Reason) VALUES ('%1', '%2')")
            .arg(ban->getID())
            .arg(ban->getReason());
}

const QString W_Ban::getUpdateQuery(QSharedPointer<Ban> ban)
{
    return QString("UPDATE Banlist SET Reason = '%1' WHERE ID_User = '%2'")
            .arg(ban->getReason())
            .arg(ban->getID());
}

