QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseClass/baseclassmainmenu.cpp \
    BaseClass/baseclasssearchwindow.cpp \
    GUI/Objects/Admin/activetable.cpp \
    GUI/Objects/Admin/ban.cpp \
    GUI/Objects/Admin/user.cpp \
    GUI/TabWidgets/Admin/activetables.cpp \
    GUI/TabWidgets/Admin/banlist.cpp \
    GUI/TabWidgets/Admin/stuffusers.cpp \
    GUI/TabWidgets/Admin/users.cpp \
    GUI/TabWidgets/welcome.cpp \
    GUI/WorkingWithRecords/Admin/w_user.cpp \
    GUI/window_admin.cpp \
    GUI/window_auth.cpp \
    GUI/Notification/notification.cpp \
    GUI/Notification/reconnecting.cpp \
    GUI/Objects/Admin/stuffuser.cpp \
    GUI/TabWidgets/Admin/credits.cpp \
    GUI/TabWidgets/Admin/payments.cpp \
    GUI/WorkingWithRecords/Admin/w_ban.cpp \
    GUI/WorkingWithRecords/Admin/w_stuffuser.cpp \
    GUI/WorkingWithRecords/Admin/w_table.cpp \
    GUI/window_player.cpp \
    Games/BlackDjack/blackjackwindow.cpp \
    Games/BlackDjack/card.cpp \
    Games/BlackDjack/deck.cpp \
    Games/BlackDjack/player.cpp \
    Games/BlackDjack/urlcard.cpp \
    Network/PacketsActions/p_authorization.cpp \
    Network/PacketsActions/p_notification.cpp \
    Network/PacketsActions/p_query.cpp \
    Network/PacketsActions/p_reconnection.cpp \
    Network/PacketsActions/p_sendmodel.cpp \
    Network/networkclient.cpp \
    Network/packethandler.cpp \
    Utils/pagination.cpp \
    Utils/searchmodule.cpp \
    Utils/serializer.cpp \
    Utils/workingistableview.cpp \
    main.cpp

HEADERS += \
    BaseClass/baseclassmainmenu.h \
    BaseClass/baseclasssearchwindow.h \
    GUI/Objects/Admin/activetable.h \
    GUI/Objects/Admin/ban.h \
    GUI/Objects/Admin/user.h \
    GUI/TabWidgets/Admin/activetables.h \
    GUI/TabWidgets/Admin/banlist.h \
    GUI/TabWidgets/Admin/stuffusers.h \
    GUI/TabWidgets/Admin/users.h \
    GUI/TabWidgets/welcome.h \
    GUI/WorkingWithRecords/Admin/w_user.h \
    GUI/window_admin.h \
    GUI/window_auth.h \
    GUI/Notification/notification.h \
    GUI/Notification/reconnecting.h \
    GUI/Objects/Admin/stuffuser.h \
    GUI/TabWidgets/Admin/credits.h \
    GUI/TabWidgets/Admin/payments.h \
    GUI/WorkingWithRecords/Admin/w_ban.h \
    GUI/WorkingWithRecords/Admin/w_stuffuser.h \
    GUI/WorkingWithRecords/Admin/w_table.h \
    GUI/window_player.h \
    Games/BlackDjack/blackjackwindow.h \
    Games/BlackDjack/card.h \
    Games/BlackDjack/cardRank.h \
    Games/BlackDjack/constant.h \
    Games/BlackDjack/deck.h \
    Games/BlackDjack/player.h \
    Games/BlackDjack/urlcard.h \
    Network/PacketTypes.h \
    Network/PacketsActions/p_authorization.h \
    Network/PacketsActions/p_notification.h \
    Network/PacketsActions/p_query.h \
    Network/PacketsActions/p_reconnection.h \
    Network/PacketsActions/p_sendmodel.h \
    Network/networkclient.h \
    Network/packethandler.h \
    Utils/Message.h \
    Utils/pagination.h \
    Utils/searchmodule.h \
    Utils/serializer.h \
    Constants.h \
    Utils/windowtracker.h \
    Utils/workingistableview.h

FORMS += \
    GUI/TabWidgets/Admin/activetables.ui \
    GUI/TabWidgets/Admin/banlist.ui \
    GUI/TabWidgets/Admin/stuffusers.ui \
    GUI/TabWidgets/Admin/users.ui \
    GUI/TabWidgets/welcome.ui \
    GUI/WorkingWithRecords/Admin/w_user.ui \
    GUI/window_admin.ui \
    GUI/window_auth.ui \
    GUI/TabWidgets/Admin/credits.ui \
    GUI/TabWidgets/Admin/payments.ui \
    GUI/WorkingWithRecords/Admin/w_ban.ui \
    GUI/WorkingWithRecords/Admin/w_stuffuser.ui \
    GUI/WorkingWithRecords/Admin/w_table.ui \
    GUI/window_player.ui \
    Games/BlackDjack/blackjackwindow.ui

LIBS += -lws2_32
QT += core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    CardGameAssets.qrc \
    Resources.qrc
