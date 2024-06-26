﻿#ifndef ADD_STUFFUSER_H
#define ADD_STUFFUSER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/Message.h"
#include "Gui/Objects/Admin/objectstuffuser.h"

namespace Ui
{
    class W_StuffUser;
}

class W_StuffUser : public QWidget
{
    Q_OBJECT

    Ui::W_StuffUser *ui;
    QueryTypes actionType;
    QSharedPointer<ObjectStuffUser> defaultStuffUser;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    const ModelTypes modelTypes = ModelTypes::StuffUsers;

public:
    explicit W_StuffUser(const QueryTypes actionType, QSharedPointer<ObjectStuffUser> defaultStuffUser = QSharedPointer<ObjectStuffUser>(new ObjectStuffUser()), QWidget *parent = nullptr);
    ~W_StuffUser();

private slots:
    void on_buttonSave_clicked();

private:
    const QString getName();
    const QString getLogin();
    const QString getPassword();
    Roles getRole();

    void loadComboBoxRole();
    void clearInput();
    void setDefaultValues();
    void onLoadForm();
    void customizationLiteEdit();

    const QString getInsertQuery(QSharedPointer<ObjectStuffUser> stuffUser);
    const QString getUpdateQuery(QSharedPointer<ObjectStuffUser> stuffUser);
};

#endif // ADD_STUFFUSER_H
