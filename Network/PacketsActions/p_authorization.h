#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include <Network/networkclient.h>
#include <GUI/window_admin.h>

class P_Authorization : public QObject
{
    Q_OBJECT

public:
    static void openMainWindow();
};

#endif // P_AUTHORIZATION_H
