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
    GUI/Objects/Admin/objectstuffuser.cpp \
    GUI/Objects/Admin/objectuser.cpp \
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
    GUI/TabWidgets/Admin/credits.cpp \
    GUI/TabWidgets/Admin/payments.cpp \
    GUI/WorkingWithRecords/Admin/w_ban.cpp \
    GUI/WorkingWithRecords/Admin/w_stuffuser.cpp \
    GUI/WorkingWithRecords/Admin/w_table.cpp \
    GUI/window_player.cpp \
    Games/BlackDjack/GUI/blackjackwindow.cpp \
    Games/Tabel/game.cpp \
    Games/Tabel/table.cpp \
    Games/card.cpp \
    Games/deck.cpp \
    Games/gamer.cpp \
    Network/PacketsActions/p_authorization.cpp \
    Network/PacketsActions/p_notification.cpp \
    Network/PacketsActions/p_query.cpp \
    Network/PacketsActions/p_reconnection.cpp \
    Network/PacketsActions/p_sendmodel.cpp \
    Network/PacketsActions/p_sendtables.cpp \
    Network/networkclient.cpp \
    Network/packethandler.cpp \
    Users/player.cpp \
    Users/stuffuser.cpp \
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
    GUI/Objects/Admin/objectstuffuser.h \
    GUI/Objects/Admin/objectuser.h \
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
    GUI/TabWidgets/Admin/credits.h \
    GUI/TabWidgets/Admin/payments.h \
    GUI/WorkingWithRecords/Admin/w_ban.h \
    GUI/WorkingWithRecords/Admin/w_stuffuser.h \
    GUI/WorkingWithRecords/Admin/w_table.h \
    GUI/window_player.h \
    Games/BlackDjack/GUI/blackjackwindow.h \
    Games/BlackDjack/constant.h \
    Games/Tabel/game.h \
    Games/Tabel/table.h \
    Games/card.h \
    Games/cardRank.h \
    Games/cardSuit.h \
    Games/deck.h \
    Games/gamer.h \
    Network/PacketTypes.h \
    Network/PacketsActions/p_authorization.h \
    Network/PacketsActions/p_notification.h \
    Network/PacketsActions/p_query.h \
    Network/PacketsActions/p_reconnection.h \
    Network/PacketsActions/p_sendmodel.h \
    Network/PacketsActions/p_sendtables.h \
    Network/networkclient.h \
    Network/packethandler.h \
    Users/player.h \
    Users/stuffuser.h \
    Users/user.h \
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
    Games/BlackDjack/GUI/blackjackwindow.ui

LIBS += -lws2_32
QT += core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    CardGameAssets.qrc \
    Resources.qrc

DISTFILES += \
    Games/BlackDjack/assets/Standart/Clubs/10.png \
    Games/BlackDjack/assets/Standart/Clubs/2.png \
    Games/BlackDjack/assets/Standart/Clubs/3.png \
    Games/BlackDjack/assets/Standart/Clubs/4.png \
    Games/BlackDjack/assets/Standart/Clubs/5.png \
    Games/BlackDjack/assets/Standart/Clubs/6.png \
    Games/BlackDjack/assets/Standart/Clubs/7.png \
    Games/BlackDjack/assets/Standart/Clubs/8.png \
    Games/BlackDjack/assets/Standart/Clubs/9.png \
    Games/BlackDjack/assets/Standart/Clubs/A.png \
    Games/BlackDjack/assets/Standart/Clubs/J.png \
    Games/BlackDjack/assets/Standart/Clubs/K.png \
    Games/BlackDjack/assets/Standart/Clubs/Q.png \
    Games/BlackDjack/assets/Standart/Clubs/Крестия.png \
    Games/BlackDjack/assets/Standart/Diamonds/10.png \
    Games/BlackDjack/assets/Standart/Diamonds/2.png \
    Games/BlackDjack/assets/Standart/Diamonds/3.png \
    Games/BlackDjack/assets/Standart/Diamonds/4.png \
    Games/BlackDjack/assets/Standart/Diamonds/5.png \
    Games/BlackDjack/assets/Standart/Diamonds/6.png \
    Games/BlackDjack/assets/Standart/Diamonds/7.png \
    Games/BlackDjack/assets/Standart/Diamonds/8.png \
    Games/BlackDjack/assets/Standart/Diamonds/9.png \
    Games/BlackDjack/assets/Standart/Diamonds/A.png \
    Games/BlackDjack/assets/Standart/Diamonds/J.png \
    Games/BlackDjack/assets/Standart/Diamonds/K.png \
    Games/BlackDjack/assets/Standart/Diamonds/Q.png \
    Games/BlackDjack/assets/Standart/Diamonds/Бубна.png \
    Games/BlackDjack/assets/Standart/Hearts/10.png \
    Games/BlackDjack/assets/Standart/Hearts/2.png \
    Games/BlackDjack/assets/Standart/Hearts/3.png \
    Games/BlackDjack/assets/Standart/Hearts/4.png \
    Games/BlackDjack/assets/Standart/Hearts/5.png \
    Games/BlackDjack/assets/Standart/Hearts/6.png \
    Games/BlackDjack/assets/Standart/Hearts/7.png \
    Games/BlackDjack/assets/Standart/Hearts/8.png \
    Games/BlackDjack/assets/Standart/Hearts/9.png \
    Games/BlackDjack/assets/Standart/Hearts/A.png \
    Games/BlackDjack/assets/Standart/Hearts/J.png \
    Games/BlackDjack/assets/Standart/Hearts/K.png \
    Games/BlackDjack/assets/Standart/Hearts/Q.png \
    Games/BlackDjack/assets/Standart/Hearts/Черва.png \
    Games/BlackDjack/assets/Standart/Spades/10.png \
    Games/BlackDjack/assets/Standart/Spades/2.png \
    Games/BlackDjack/assets/Standart/Spades/3.png \
    Games/BlackDjack/assets/Standart/Spades/4.png \
    Games/BlackDjack/assets/Standart/Spades/5.png \
    Games/BlackDjack/assets/Standart/Spades/6.png \
    Games/BlackDjack/assets/Standart/Spades/7.png \
    Games/BlackDjack/assets/Standart/Spades/8.png \
    Games/BlackDjack/assets/Standart/Spades/9.png \
    Games/BlackDjack/assets/Standart/Spades/A.png \
    Games/BlackDjack/assets/Standart/Spades/J.png \
    Games/BlackDjack/assets/Standart/Spades/K.png \
    Games/BlackDjack/assets/Standart/Spades/Q.png \
    Games/BlackDjack/assets/Standart/Spades/Пика.png \
    Games/BlackDjack/assets/Standart/shirt.png \
    Games/BlackDjack/assets/Колода.png
