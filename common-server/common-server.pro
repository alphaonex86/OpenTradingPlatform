#-------------------------------------------------
#
# Project created by QtCreator 2013-12-30T18:16:00
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = common-server
TEMPLATE = lib

DEFINES += COMMONSERVER_LIBRARY

SOURCES += commonserver.cpp

HEADERS += commonserver.h\
        common-server_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
