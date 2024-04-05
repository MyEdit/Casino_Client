#ifndef ADD_STUFFUSER_H
#define ADD_STUFFUSER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/notificationutil.h"
#include "Utils/Message.h"
#include "GUI/Objects/Admin/objectstuffuser.h"

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

public:
    explicit W_StuffUser(QueryTypes actionType, QSharedPointer<ObjectStuffUser> defaultStuffUser = QSharedPointer<ObjectStuffUser>(new ObjectStuffUser()), QWidget *parent = nullptr);
    ~W_StuffUser();

private slots:
    void on_buttonSave_clicked();

private:
    QString getName();
    QString getLogin();
    QString getPassword();
    Roles getRole();

    void loadComboBoxRole();
    void clearInput();
    void setDefaultValues();
    void onLoadForm();
    void customizationLiteEdit();

    QString getInsertQuery(QSharedPointer<ObjectStuffUser> stuffUser);
    QString getUpdateQuery(QSharedPointer<ObjectStuffUser> stuffUser);
};

#endif // ADD_STUFFUSER_H
