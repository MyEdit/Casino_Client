#ifndef W_USER_H
#define W_USER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/notificationutil.h"
#include "Utils/Message.h"
#include "GUI/Objects/Admin/objectuser.h"

namespace Ui {
class W_User;
}

class W_User : public QWidget
{
    Q_OBJECT

    Ui::W_User *ui;
    QueryTypes actionType;
    QSharedPointer<ObjectUser> defaultUser;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;

public:
    explicit W_User(QueryTypes actionType, QSharedPointer<ObjectUser> defaultUser = QSharedPointer<ObjectUser>(new ObjectUser()), QWidget *parent = nullptr);
    ~W_User();


private slots:
    void on_buttonSave_clicked();

private:
    QString getName();
    QString getPassport();
    QString getBalance();
    QString getLogin();
    QString getPassword();

    void clearInput();
    void setDefaultValues();
    void onLoadForm();
    void customizationLiteEdit();

    QString getInsertQuery(QSharedPointer<ObjectUser> user);
    QString getUpdateQuery(QSharedPointer<ObjectUser> user);
};

#endif // W_USER_H
