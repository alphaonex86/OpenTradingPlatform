#include <QDebug>

#include "fundserver.h"

FundServer::FundServer(){

}

void FundServer::startServer(int port)
{
    this->server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));
    if (!server->listen(QHostAddress::Any, port)){
        qDebug() << "Failed to Listen";
    }
}

void FundServer::on_newConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();
    //do some communication...
}
