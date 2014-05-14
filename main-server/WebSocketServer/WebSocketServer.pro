#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T00:40:59
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT += websockets

TARGET = WebSocketServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    BCWebSocketServer.cpp \
    fundssocket.cpp \
    sqlhandler.cpp \
    configfunctions.cpp \
    Request/requestrefresh.cpp \
    Request/requestsell.cpp \
    Request/requestbuy.cpp \
    smtp.cpp \
    translationmanager.cpp \
    translationslang.cpp \
    Request/requestlang.cpp \
    Request/requestlogin.cpp

HEADERS += \
    BCWebSocketServer.h \
    fundssocket.h \
    sqlhandler.h \
    sqldata.h \
    request.h \
    configfunctions.h \
    Request/request.h \
    Request/requestrefresh.h \
    Request/requestsell.h \
    Request/requestbuy.h \
    smtp.h \
    translationmanager.h \
    translationslang.h \
    Request/requestlang.h \
    Request/requestlogin.h

OTHER_FILES += \
    database.sql

RESOURCES += \
    Resource.qrc


win32 {
QMAKE_LIBDIR += "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\lib" "C:\Program Files (x86)\Windows Kits\8.0\Lib\win8\um\x86"
LIBS += -l"C:\Program Files (x86)\Windows Kits\8.0\Lib\win8\um\x86\setupapi" -l"C:\Program Files (x86)\Windows Kits\8.0\Lib\win8\um\x86\uuid" -l"C:\Program Files (x86)\Windows Kits\8.0\Lib\win8\um\x86\advapi32"

INCLUDEPATH += "C:\Program Files (x86)\Windows Kits\8.0\Include\um" "C:\Program Files (x86)\Windows Kits\8.0\Include\shared" "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\include"
}
