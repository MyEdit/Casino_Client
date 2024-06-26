﻿#include "w_stuffuser.h"
#include "ui_w_stuffuser.h"

W_StuffUser::W_StuffUser(const QueryTypes actionType, QSharedPointer<ObjectStuffUser> defaultStuffUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::W_StuffUser), actionType(actionType), defaultStuffUser(defaultStuffUser)
{
    ui->setupUi(this);
    loadComboBoxRole();
    onLoadForm();
    customizationLiteEdit();
    setAttribute(Qt::WA_ShowModal, true);
}

W_StuffUser::~W_StuffUser()
{
    delete ui;
}

void W_StuffUser::onLoadForm()
{
    switch (actionType)
    {
        case QueryTypes::CreateEntry:
        {
            connect(ui->buttonReset, &QPushButton::clicked, this, &W_StuffUser::clearInput);
            setWindowTitle("Добавление сотрудника");
            break;
        }
        case QueryTypes::UpdateEntry:
        {
            connect(ui->buttonReset, &QPushButton::clicked, this, &W_StuffUser::setDefaultValues);
            setWindowTitle("Редактирование сотрудника");
            setDefaultValues();
            break;
        }
        default:
            this->close();
    };
}

void W_StuffUser::on_buttonSave_clicked()
{
    QSharedPointer<ObjectStuffUser> stuffUser = QSharedPointer<ObjectStuffUser>::create(defaultStuffUser->getID(), getName(), getLogin(), getPassword(), getRole());
    QString query;

    if (!stuffUser->inputDataIsValid())
    {
                Notification::showNotification(TypeMessage::Error, "Заполнены не все поля");
        return;
    }

    if (actionType == QueryTypes::CreateEntry)
        query = getInsertQuery(stuffUser);
    else
        query = getUpdateQuery(stuffUser);

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modelTypes, sizeof(ModelTypes));
    NetworkClient::sendToServer(&actionType, sizeof(QueryTypes));
    NetworkClient::sendToServer(query);

    this->close();
}

const QString W_StuffUser::getInsertQuery(QSharedPointer<ObjectStuffUser> stuffUser)
{
    return QString("INSERT INTO StuffUsers (Name, Login, Password, ID_Role) VALUES ('%1', '%2', '%3', '%4')")
            .arg(stuffUser->getFullName())
            .arg(stuffUser->getLogin())
            .arg(stuffUser->getPassword())
            .arg(static_cast<int>(stuffUser->getRole()));
}

const QString W_StuffUser::getUpdateQuery(QSharedPointer<ObjectStuffUser> stuffUser)
{
    return QString("UPDATE StuffUsers SET Name = '%1', Login = '%2', Password = '%3', ID_Role = '%4' WHERE ID_StuffUser = '%5'")
            .arg(stuffUser->getFullName())
            .arg(stuffUser->getLogin())
            .arg(stuffUser->getPassword())
            .arg(static_cast<int>(stuffUser->getRole()))
            .arg(stuffUser->getID());
}

void W_StuffUser::loadComboBoxRole()
{
    ui->ComboBoxRoles->addItem("Администратор");
    ui->ComboBoxRoles->addItem("Распорядитель столов");
}

const QString W_StuffUser::getName()
{
    return ui->InputName->text();
}

const QString W_StuffUser::getLogin()
{
    return ui->InputLogin->text();
}

const QString W_StuffUser::getPassword()
{
    return ui->InputPassword->text();
}

Roles W_StuffUser::getRole()
{
    return static_cast<Roles>(ui->ComboBoxRoles->currentIndex() + 1);
}

void W_StuffUser::setDefaultValues()
{
    ui->InputName->setText(defaultStuffUser->getFullName());
    ui->InputLogin->setText(defaultStuffUser->getLogin());
    ui->InputPassword->setText(defaultStuffUser->getPassword());
    ui->ComboBoxRoles->setCurrentText(BaseClassMainMenu::getTextRole(defaultStuffUser->getRole()));
}

void W_StuffUser::clearInput()
{
    for(QLineEdit* lineEdit : this->findChildren<QLineEdit*>())
    {
        lineEdit->clear();
    }
    ui->ComboBoxRoles->setCurrentIndex(0);
}

void W_StuffUser::customizationLiteEdit()
{
    ui->InputName->setValidator(new QRegExpValidator(QRegExp("[^\\d\\W_]+(\\s+[^\\d\\W_]+)*"))); // Для установки что можно вводить только текст
}
