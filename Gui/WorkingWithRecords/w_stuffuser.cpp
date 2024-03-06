#include "w_stuffuser.h"
#include "ui_w_stuffuser.h"

W_StuffUser::W_StuffUser(WorkingWithDataType type, QSharedPointer<StuffUser> stuffUser, QWidget *parent)
    : QWidget(parent), ui(new Ui::W_StuffUser), type(type), stuffUser(stuffUser)
{
    ui->setupUi(this);
    loadComboBoxRole();
    connects();
}

W_StuffUser::~W_StuffUser()
{
    delete ui;
}

void W_StuffUser::add()
{
    stuffUser = QSharedPointer<StuffUser>::create(getName(), getLogin(), getPassword(), getRole());

    if (!stuffUser->inputDataIsValid())
    {
        NotificationUtil::viewNotification({TypeMessage::Error, "Заполнены не все поля"});
        return;
    }

    QString query = QString("INSERT INTO StuffUsers (Name, Login, Password, ID_Role) VALUES ('%1', '%2', '%3', %4)")
            .arg(stuffUser->getFullName())
            .arg(stuffUser->getLogin())
            .arg(stuffUser->getPassword())
            .arg(static_cast<int>(stuffUser->getRole()));

    NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    NetworkClient::sendToServer(&modeltype, sizeof(ModelTypes)); //TODO: Удалить
    NetworkClient::sendToServer(&querytype, sizeof(QueryTypes));
    NetworkClient::sendToServer(query);

    this->close();
}

//По хорошему объединить его с add, и назвать метод on_buttonSave_clicked, и лишь по WorkingWithDataType подменять запрос
void W_StuffUser::update()
{
    //TODO: Coming soon...
}

void W_StuffUser::connects()
{
    switch (type)
    {
        case WorkingWithDataType::Add:
        {
            connect(ui->buttonSave, &QPushButton::clicked, this, &W_StuffUser::add);
            connect(ui->buttonReset, &QPushButton::clicked, this, &W_StuffUser::clearInput);
            setWindowTitle("Добавление сотрудника");
            break;
        }
        case WorkingWithDataType::Update:
        {
            connect(ui->buttonSave, &QPushButton::clicked, this, &W_StuffUser::update);
            connect(ui->buttonReset, &QPushButton::clicked, this, &W_StuffUser::resetInputs);
            setWindowTitle("Редактирование сотрудника");
            break;
        }
    };
}

void W_StuffUser::loadComboBoxRole()
{
    //TODO: Обдумать использование метапрограммирования для заполнения комбобоксов, может действительно проще и удобнее
    //создать под каждый енум свой класс и использовать такой подход за место стандартных игр с индексами
    //ui->ComboBoxRoles->addItem("Администратор", QVariant::fromValue(Roles::Admin));
    ui->ComboBoxRoles->addItem("Администратор");
    ui->ComboBoxRoles->addItem("Распорядитель столов");
}

QString W_StuffUser::getName()
{
    return ui->InputName->text();
}

QString W_StuffUser::getLogin()
{
    return ui->InputLogin->text();
}

QString W_StuffUser::getPassword()
{
    return ui->InputPassword->text();
}

Roles W_StuffUser::getRole()
{
    return static_cast<Roles>(ui->ComboBoxRoles->currentIndex() + 1);
}

void W_StuffUser::resetInputs()
{
    //TODO: Coming soon...
}

void W_StuffUser::clearInput()
{
    for(QLineEdit* lineEdit : this->findChildren<QLineEdit*>())
    {
        lineEdit->clear();
    }
    ui->ComboBoxRoles->setCurrentIndex(0);
}
