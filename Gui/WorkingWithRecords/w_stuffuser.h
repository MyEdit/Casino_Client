﻿#ifndef ADD_STUFFUSER_H
#define ADD_STUFFUSER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/notificationutil.h"
#include "Utils/Message.h"

namespace Ui
{
    class W_StuffUser;
}

class W_StuffUser : public QWidget
{
    Q_OBJECT

    struct StuffUserData
    {
        QString name;
        QString login;
        QString password;
        Roles role;
    };

    Ui::W_StuffUser *ui;
    WorkingWithDataType type;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    const ModelTypes modeltype = ModelTypes::StuffUsers;
    const QueryTypes querytype = QueryTypes::CreateEntry;

public:
    explicit W_StuffUser(WorkingWithDataType type, QWidget *parent = nullptr); //TODO: нужно передоавть сюда данные из выбранной строки, можно наверное для это использовать StuffUserData, если WorkingWithDataType == Add, то пихать туда nullptr
    ~W_StuffUser();

private:
    QString getName();
    QString getLogin();
    QString getPassword();
    Roles getRole();
    void loadComboBoxRole();
    void resetInputs();
    void clearInput();
    bool validateInputData(StuffUserData inputData);
    void add();
    void update();
    void connects();
};

#endif // ADD_STUFFUSER_H
