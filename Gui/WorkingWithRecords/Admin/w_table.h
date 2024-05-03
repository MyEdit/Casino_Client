#ifndef ADD_TABLE_H
#define ADD_TABLE_H

#include <QWidget>
#include "Network/networkclient.h"
#include "Network/PacketTypes.h"
#include "Utils/Message.h"
#include "Gui/Objects/Admin/activetable.h"

namespace Ui {
class W_Table;
}

class W_Table : public QWidget
{
    Q_OBJECT

    Ui::W_Table *ui;
    QueryTypes actionType;
    QSharedPointer<ActiveTable> defaultActiveTable;
    const PacketTypes packettype = PacketTypes::P_QueryWithoutResponce;

public:
    explicit W_Table(const QueryTypes actionType, QSharedPointer<ActiveTable> defaultActiveTable = QSharedPointer<ActiveTable>(new ActiveTable()), QWidget *parent = nullptr);
    ~W_Table();

private slots:
    void on_bottonSave_clicked();

private:
    const QString getMaxPlayers();
    const QString getMinBet();
    const QString getBetStep();
    const QString getMinBalance();
    const QString getNameGame();

    void loadComboBoxNameGame();
    void clearInput();
    void setDefaultValues();
    void onLoadForm();
    void customizationLiteEdit();

    const QString getInsertQuery(QSharedPointer<ActiveTable> activeTable);
    const QString getUpdateQuery(QSharedPointer<ActiveTable> activeTable);
};

#endif // ADD_TABLE_H
