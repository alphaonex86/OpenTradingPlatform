#include <QCoreApplication>
#include <QHostAddress>
#include <QLibrary>

#include "fundssocket.h"
#include "websockethandler.h"
#include "sqlhandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FundsSocket* socket = new FundsSocket();
    socket->loadConfig("config.ini");

    SqlHandler* sqlHandler = new SqlHandler();
    sqlHandler->loadConfig("config.ini");

    WebsocketHandler* wsHandler = new WebsocketHandler();
    wsHandler->createRequest();
    wsHandler->startServer(8080, QtWebsocket::Tcp);
    wsHandler->setSqlHandler(sqlHandler);

    return a.exec();
}
