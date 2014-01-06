#-------------------------------------------------
#
# Project created by QtCreator 2013-12-30T17:12:10
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = funds-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fundserver.cpp \
    fundsclient.cpp \
    packet.cpp

HEADERS += \
    fundserver.h \
    bitcoininterface.h \
    bankinterface.h \
    fundsclient.h \
    packet.h
