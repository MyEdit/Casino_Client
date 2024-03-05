#ifndef ADD_STUFFUSER_H
#define ADD_STUFFUSER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/notificationutil.h"
#include "Utils/Message.h"

namespace Ui
{
    class Add_StuffUser;
}

class Add_StuffUser : public QWidget
{
    Q_OBJECT

    struct StuffUserData
    {
        QString name;
        QString login;
        QString password;
        Roles role;
    };

    Ui::Add_StuffUser *ui;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    const ModelTypes modeltype = ModelTypes::StuffUsers;
    const QueryTypes querytype = QueryTypes::CreateEntry;

public:
    explicit Add_StuffUser(QWidget *parent = nullptr);
    ~Add_StuffUser();

private:
    QString getName();
    QString getLogin();
    QString getPassword();
    Roles getRole();
    void loadComboBoxRole();
    void resetInputs();
    bool validateInputData(StuffUserData inputData);

private slots:
    void on_buttonSave_clicked();
    void on_buttonReset_clicked();
};

#endif // ADD_STUFFUSER_H
