#ifndef ADD_STUFFUSER_H
#define ADD_STUFFUSER_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/notificationutil.h"
#include "Utils/Message.h"
#include "GUI/Objects/stuffuser.h"

namespace Ui
{
    class W_StuffUser;
}

class W_StuffUser : public QWidget
{
    Q_OBJECT

    Ui::W_StuffUser *ui;
    WorkingWithDataType type;
    QSharedPointer<StuffUser> stuffUser;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;
    const ModelTypes modeltype = ModelTypes::StuffUsers;
    const QueryTypes querytype = QueryTypes::CreateEntry;

public:
    explicit W_StuffUser(WorkingWithDataType type, QSharedPointer<StuffUser> stuffUser = nullptr, QWidget *parent = nullptr); //TODO: нужно передоавть сюда данные из выбранной строки, можно наверное для это использовать StuffUserData, если WorkingWithDataType == Add, то пихать туда nullptr
    ~W_StuffUser();

private:
    QString getName();
    QString getLogin();
    QString getPassword();
    Roles getRole();
    void loadComboBoxRole();
    void resetInputs();
    void clearInput();
    void add();
    void update();
    void connects();
};

#endif // ADD_STUFFUSER_H
