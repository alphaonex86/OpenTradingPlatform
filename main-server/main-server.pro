#-------------------------------------------------
#
# Project created by QtCreator 2013-12-30T17:13:50
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = main-server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/ -lQtWebsocket
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/ -lQtWebsocketd
else:unix: LIBS += -L$$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/ -lQtWebsocket

INCLUDEPATH += $$PWD/qtwebsocket-qtwebsocket/QtWebsocket
DEPENDPATH += $$PWD/qtwebsocket-qtwebsocket/QtWebsocket

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/libQtWebsocket.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/libQtWebsocketd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/QtWebsocket.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/QtWebsocketd.lib
else:unix: PRE_TARGETDEPS += $$PWD/build-QtWebsocket-Desktop_Qt_5_2_0_MinGW_32bit-Debug/QtWebsocket/debug/libQtWebsocket.a
