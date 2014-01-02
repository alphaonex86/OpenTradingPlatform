#-------------------------------------------------
#
# Project created by QtCreator 2013-12-30T17:13:50
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = main-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fundssocket.cpp

INCLUDEPATH += $$PWD/qtwebsocket-qtwebsocket/QtWebsocket

HEADERS += \
    fundssocket.h
