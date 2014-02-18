#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T17:04:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = bank
TEMPLATE = lib
CONFIG += plugin

SOURCES += bankplugin.cpp

HEADERS += bankplugin.h \
    ../funds-server/bankinterface.h
OTHER_FILES += BankPlugin.json
