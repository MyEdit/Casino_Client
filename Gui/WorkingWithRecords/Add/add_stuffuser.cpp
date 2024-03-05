#include "add_stuffuser.h"
#include "ui_add_stuffuser.h"

Add_StuffUser::Add_StuffUser(QWidget *parent) : QWidget(parent), ui(new Ui::Add_StuffUser)
{
    ui->setupUi(this);
    loadComboBoxRole();
}

Add_StuffUser::~Add_StuffUser()
{
    delete ui;
}

void Add_StuffUser::on_buttonSave_clicked()
{
    StuffUserData inputData { getName(), getLogin(), getPassword(), getRole() };

    if (!validateInputData(inputData))
    {
        NotificationUtil::viewNotification({TypeMessage::Error, "Заполнены не все поля"});
        return;
    }

    //NetworkClient::sendToServer(&packettype, sizeof(PacketTypes));
    //NetworkClient::sendToServer(&modeltype, sizeof(ModelTypes));
    //NetworkClient::sendToServer(&querytype, sizeof(QueryTypes));
    //NetworkClient::sendToServer(&inputData, sizeof(StuffUserData));

    this->close();
}

void Add_StuffUser::on_buttonReset_clicked()
{
    resetInputs();
}

bool Add_StuffUser::validateInputData(StuffUserData inputData)
{
    if (inputData.role == Roles::None)
        return false;

    for (QString value : {inputData.name, inputData.login, inputData.password})
    {
        if (value.isEmpty())
        {
            return false;
        }
    }

    return true;
}

void Add_StuffUser::loadComboBoxRole()
{
    //TODO: Обдумать использование метапрограммирования для заполнения комбобоксов, может действительно проще и удобнее
    //создать под каждый енум свой класс и использовать такой подход за место стандартных игр с индексами
    //ui->ComboBoxRoles->addItem("Администратор", QVariant::fromValue(Roles::Admin));
    ui->ComboBoxRoles->addItem("Администратор");
    ui->ComboBoxRoles->addItem("Распорядитель столов");
}

QString Add_StuffUser::getName()
{
    return ui->InputName->text();
}

QString Add_StuffUser::getLogin()
{
    return ui->InputLogin->text();
}

QString Add_StuffUser::getPassword()
{
    return ui->InputPassword->text();
}

Roles Add_StuffUser::getRole()
{
    return static_cast<Roles>(ui->ComboBoxRoles->currentIndex() + 1);
}

void Add_StuffUser::resetInputs()
{
    for(QLineEdit* lineEdit : this->findChildren<QLineEdit*>())
    {
        lineEdit->clear();
    }
    ui->ComboBoxRoles->setCurrentIndex(0);
}
