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
    GUI/TabWidgets/allusers.cpp \
    GUI/TabWidgets/creategametable.cpp \
    GUI/TabWidgets/existingtables.cpp \
    GUI/TabWidgets/welcome.cpp \
    GUI/window_admin.cpp \
    GUI/window_auth.cpp \
    Network/PacketsActions/p_authorization.cpp \
    Network/PacketsActions/p_query.cpp \
    Network/PacketsActions/p_sendmodel.cpp \
    Network/networkclient.cpp \
    Network/packethandler.cpp \
    Utils/pagination.cpp \
    Utils/serializer.cpp \
    Utils/workingistableview.cpp \
    main.cpp \

HEADERS += \
    GUI/TabWidgets/allusers.h \
    GUI/TabWidgets/creategametable.h \
    GUI/TabWidgets/existingtables.h \
    GUI/TabWidgets/welcome.h \
    GUI/window_admin.h \
    GUI/window_auth.h \
    Network/PacketTypes.h \
    Network/PacketsActions/p_authorization.h \
    Network/PacketsActions/p_query.h \
    Network/PacketsActions/p_sendmodel.h \
    Network/networkclient.h \
    Network/packethandler.h \
    Utils/Message.h \
    Utils/pagination.h \
    Utils/serializer.h \
    Constants.h \ \
    Utils/workingistableview.h

FORMS += \
    GUI/TabWidgets/allusers.ui \
    GUI/TabWidgets/creategametable.ui \
    GUI/TabWidgets/existingtables.ui \
    GUI/TabWidgets/welcome.ui \
    GUI/window_admin.ui \
    GUI/window_auth.ui \

LIBS += -lws2_32
QT += core

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
