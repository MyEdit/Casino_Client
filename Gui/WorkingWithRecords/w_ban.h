﻿#ifndef ADD_BAN_H
#define ADD_BAN_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/notificationutil.h"
#include "Utils/Message.h"
#include "Gui/Objects/ban.h"

namespace Ui {
class W_Ban;
}

class W_Ban : public QWidget
{
    Q_OBJECT

    Ui::W_Ban *ui;
    QueryTypes actionType;
    QSharedPointer<Ban> defaultBan;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;

public:
    explicit W_Ban(QueryTypes actionType, QSharedPointer<Ban> defaultBan, QWidget *parent = nullptr);
    ~W_Ban();

private slots:
    void on_buttonSave_clicked();

private:
    QString getReason();

    void clearInput();
    void setDefaultValues();
    void onLoadForm();

    QString getInsertQuery(QSharedPointer<Ban> ban);
    QString getUpdateQuery(QSharedPointer<Ban> ban);
};

#endif // ADD_BAN_H
