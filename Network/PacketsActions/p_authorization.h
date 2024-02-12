﻿#ifndef P_AUTHORIZATION_H
#define P_AUTHORIZATION_H

#include "Network/networkclient.h"
#include "GUI/window_admin.h"
#include <QApplication>

class Window_Admin;

class P_Authorization : public QObject
{
    Q_OBJECT
public:
    static Window_Admin* adminW;

    static void openMainWindow();
};

#endif // P_AUTHORIZATION_H
