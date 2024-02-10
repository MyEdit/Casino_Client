#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include <Network/networkclient.h>
#include <GUI/window_admin.h>
#include <QApplication>

class P_Authorization : public QObject
{
    Q_OBJECT
    static Window_Admin* adminW;

public:
    static void openMainWindow();
    static void setModelAllUsers(QStandardItemModel* model);

};

#endif // P_AUTHORIZATION_H
