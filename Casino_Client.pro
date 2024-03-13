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
    BaseClass/baseclasssearchwindow.cpp \
    GUI/Objects/activetable.cpp \
    GUI/Objects/ban.cpp \
    GUI/Objects/user.cpp \
    GUI/TabWidgets/activetables.cpp \
    GUI/TabWidgets/banlist.cpp \
    GUI/TabWidgets/stuffusers.cpp \
    GUI/TabWidgets/users.cpp \
    GUI/TabWidgets/welcome.cpp \
    GUI/WorkingWithRecords/w_user.cpp \
    GUI/window_admin.cpp \
    GUI/window_auth.cpp \
    GUI/Notification/notification.cpp \
    GUI/Notification/reconnecting.cpp \
    GUI/Objects/stuffuser.cpp \
    GUI/TabWidgets/credits.cpp \
    GUI/TabWidgets/payments.cpp \
    GUI/WorkingWithRecords/w_ban.cpp \
    GUI/WorkingWithRecords/w_stuffuser.cpp \
    GUI/WorkingWithRecords/w_table.cpp \
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
    BaseClass/baseclasssearchwindow.h \
    GUI/Objects/activetable.h \
    GUI/Objects/ban.h \
    GUI/Objects/user.h \
    GUI/TabWidgets/activetables.h \
    GUI/TabWidgets/banlist.h \
    GUI/TabWidgets/stuffusers.h \
    GUI/TabWidgets/users.h \
    GUI/TabWidgets/welcome.h \
    GUI/WorkingWithRecords/w_user.h \
    GUI/window_admin.h \
    GUI/window_auth.h \
    GUI/Notification/notification.h \
    GUI/Notification/reconnecting.h \
    GUI/Objects/stuffuser.h \
    GUI/TabWidgets/credits.h \
    GUI/TabWidgets/payments.h \
    GUI/WorkingWithRecords/w_ban.h \
    GUI/WorkingWithRecords/w_stuffuser.h \
    GUI/WorkingWithRecords/w_table.h \
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
    GUI/TabWidgets/activetables.ui \
    GUI/TabWidgets/banlist.ui \
    GUI/TabWidgets/stuffusers.ui \
    GUI/TabWidgets/users.ui \
    GUI/TabWidgets/welcome.ui \
    GUI/WorkingWithRecords/w_user.ui \
    GUI/window_admin.ui \
    GUI/window_auth.ui \
    GUI/TabWidgets/credits.ui \
    GUI/TabWidgets/payments.ui \
    GUI/WorkingWithRecords/w_ban.ui \
    GUI/WorkingWithRecords/w_stuffuser.ui \
    GUI/WorkingWithRecords/w_table.ui

LIBS += -lws2_32
QT += core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
