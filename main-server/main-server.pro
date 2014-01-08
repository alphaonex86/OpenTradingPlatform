#-------------------------------------------------
#
# Project created by QtCreator 2013-12-30T17:13:50
#
#-------------------------------------------------

QT       += core
QT       += network
QT       += sql

QT       -= gui

TARGET = main-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fundssocket.cpp \
    QtWebsocket/functions.cpp \
    QtWebsocket/QTlsServer.cpp \
    QtWebsocket/QWsFrame.cpp \
    QtWebsocket/QWsHandshake.cpp \
    QtWebsocket/QWsServer.cpp \
    QtWebsocket/QWsSocket.cpp \
    client.cpp \
    sqlhandler.cpp \
    Request/requestrefresh.cpp \
    websockethandler.cpp \
    configfunctions.cpp

HEADERS += \
    fundssocket.h \
    QtWebsocket/functions.h \
    QtWebsocket/QTlsServer.h \
    QtWebsocket/QWsFrame.h \
    QtWebsocket/QWsHandshake.h \
    QtWebsocket/QWsServer.h \
    QtWebsocket/QWsSocket.h \
    QtWebsocket/WsEnums.h \
    client.h \
    sqlhandler.h \
    sqldata.h \
    request.h \
    Request/request.h \
    Request/requestrefresh.h \
    websockethandler.h \
    configfunctions.h

OTHER_FILES += \
    database.sql

RESOURCES += \
    Resource.qrc

