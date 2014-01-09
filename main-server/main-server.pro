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
    client.cpp \
    sqlhandler.cpp \
    websockethandler.cpp \
    configfunctions.cpp \
    QtWebsocket/functions.cpp \
    QtWebsocket/QTlsServer.cpp \
    QtWebsocket/QWsFrame.cpp \
    QtWebsocket/QWsHandshake.cpp \
    QtWebsocket/QWsServer.cpp \
    QtWebsocket/QWsSocket.cpp \
    Request/requestrefresh.cpp \
    Request/requestsell.cpp \
    Request/requestbuy.cpp \
    smtp.cpp \
    translationmanager.cpp \
    translationslang.cpp \
    Request/requestlang.cpp

HEADERS += \
    fundssocket.h \
    client.h \
    sqlhandler.h \
    sqldata.h \
    request.h \
    websockethandler.h \
    configfunctions.h \
    QtWebsocket/functions.h \
    QtWebsocket/QTlsServer.h \
    QtWebsocket/QWsFrame.h \
    QtWebsocket/QWsHandshake.h \
    QtWebsocket/QWsServer.h \
    QtWebsocket/QWsSocket.h \
    QtWebsocket/WsEnums.h \
    Request/request.h \
    Request/requestrefresh.h \
    Request/requestsell.h \
    Request/requestbuy.h \
    smtp.h \
    translationmanager.h \
    translationslang.h \
    Request/requestlang.h

OTHER_FILES += \
    database.sql

RESOURCES += \
    Resource.qrc

