#include <QCoreApplication>
#include <QHostAddress>

#include "fundssocket.h"
#include "websockethandle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FundsSocket* socket = new FundsSocket();
    socket->connectToHost(QHostAddress::LocalHost, 64542);

    WebsocketHandle* handle = new WebsocketHandle();
    handle->startServer(8080, QtWebsocket::Tcp);

    return a.exec();
}
