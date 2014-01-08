#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T17:04:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = bitcoin
TEMPLATE = lib
CONFIG += plugin

SOURCES += bitcoinplugin.cpp

HEADERS += bitcoinplugin.h \
    ../funds-server/bitcoininterface.h
OTHER_FILES += BitcoinPlugin.json

