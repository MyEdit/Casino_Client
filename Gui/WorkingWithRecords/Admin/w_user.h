#ifndef W_USER_H
#define W_USER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/Message.h"
#include "Gui/Objects/Admin/objectuser.h"

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
    const ModelTypes modelTypes = ModelTypes::Users;

public:
    explicit W_User(const QueryTypes actionType, QSharedPointer<ObjectUser> defaultUser = QSharedPointer<ObjectUser>(new ObjectUser()), QWidget *parent = nullptr);
    ~W_User();


private slots:
    void on_buttonSave_clicked();

private:
    const QString getName();
    const QString getPassport();
    const QString getBalance();
    const QString getLogin();
    const QString getPassword();

    void clearInput();
    void setDefaultValues();
    void onLoadForm();
    void customizationLiteEdit();

    const QString getInsertQuery(QSharedPointer<ObjectUser> user);
    const QString getUpdateQuery(QSharedPointer<ObjectUser> user);
};

#endif // W_USER_H
