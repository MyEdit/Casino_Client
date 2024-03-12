#include "w_user.h"
#include "ui_w_user.h"

W_User::W_User(QueryTypes actionType, QSharedPointer<User> defaultUser, QWidget *parent) :
    QWidget(parent), ui(new Ui::W_User), actionType(actionType), defaultUser(defaultUser)
{
    ui->setupUi(this);
    onLoadForm();
    customizationLiteEdit();
}

W_User::~W_User()
{
    delete ui;
}

void W_User::on_buttonSave_clicked()
{
    QSharedPointer<User> user = QSharedPointer<User>::create(defaultUser->getID(), getName(), getPassport(), getBalance(), getLogin(), getPassword());
    QString query;

    if (!user->inputDataIsValid())
    {
        NotificationUtil::viewNotification({TypeMessage::Error, "Заполнены не все поля"});
        return;
    }

    if (actionType == QueryTypes::CreateEntry)
        query = getInsertQuery(user);
    else
        query = getUpdateQuery(user);

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&actionType, sizeof(QueryTypes));
    NetworkClient::sendToServer(query);

    this->close();
}

QString W_User::getName()
{
    return ui->InputName->text();
}

QString W_User::getPassport()
{
    return ui->InputPassport->text();
}

QString W_User::getBalance()
{
    return ui->InputBalance->text();
}

QString W_User::getLogin()
{
    return ui->InputLogin->text();
}

QString W_User::getPassword()
{
    return ui->InputPassword->text();
}

void W_User::clearInput()
{
    for(QLineEdit* lineEdit : this->findChildren<QLineEdit*>())
    {
        lineEdit->clear();
    }
}

void W_User::setDefaultValues()
{
    ui->InputName->setText(defaultUser->getFullName());
    ui->InputPassport->setText(defaultUser->getPassport());
    ui->InputBalance->setText(defaultUser->getBalance());
    ui->InputLogin->setText(defaultUser->getLogin());
    ui->InputPassword->setText(defaultUser->getPassword());
}

void W_User::onLoadForm()
{
    switch (actionType)
    {
    case QueryTypes::CreateEntry:
    {
        connect(ui->buttonReset, &QPushButton::clicked, this, &W_User::clearInput);
        setWindowTitle("Добавление пользователя");
        break;
    }
    case QueryTypes::UpdateEntry:
    {
        connect(ui->buttonReset, &QPushButton::clicked, this, &W_User::setDefaultValues);
        setWindowTitle("Редактирование пользователя");
        setDefaultValues();
        break;
    }
    default:
        this->close();
    };
}

void W_User::customizationLiteEdit()
{
    ui->InputName->setValidator(new QRegExpValidator(QRegExp("[^\\d\\W_]+")));
    ui->InputPassport->setValidator(new QIntValidator(this));
    ui->InputBalance->setValidator(new QIntValidator(this));
}

QString W_User::getInsertQuery(QSharedPointer<User> user)
{
    return QString("INSERT INTO Users (Name, Passport, Balance, Login, Password, ID_Role) VALUES ('%1', '%2', '%3', '%4', '%5', '%6')")
            .arg(user->getFullName())
            .arg(user->getPassport())
            .arg(user->getBalance())
            .arg(user->getLogin())
            .arg(user->getPassword())
            .arg(static_cast<int>(user->getRole()));
}

QString W_User::getUpdateQuery(QSharedPointer<User> user)
{
    return QString("UPDATE Users SET Name = '%1', Passport = '%2', Balance = '%3', Login = '%4', Password = '%5', ID_Role = '%6' WHERE ID_User = '%7'")
            .arg(user->getFullName())
            .arg(user->getPassport())
            .arg(user->getBalance())
            .arg(user->getLogin())
            .arg(user->getPassword())
            .arg(static_cast<int>(user->getRole()))
            .arg(user->getID());
}
