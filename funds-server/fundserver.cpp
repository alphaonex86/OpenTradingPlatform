#include <QDebug>
#include <QTcpSocket>

#include "fundserver.h"

FundServer::FundServer(){

}

bool FundServer::startServer(int port)
{
    this->server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));
    if (!server->listen(QHostAddress::Any, port)){
        qDebug() << "Failed to Listen";
        return false;
    }
    return true;
}

void FundServer::onNewConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();
    if(socket->waitForReadyRead()){

    }
    else{
        socket->abort();
    }
}

QString FundServer::readString(QTcpSocket *socket)
{
    // String size
    QByteArray readData = socket->read(1);

    // String data
    return QString(socket->read(readData[0]));
}

void FundServer::askNewConnection(QTcpSocket* socket)
{
    // Login
    QString login = readString(socket);

    // Password
    QString password = readString(socket);

    if(!loginValid(login, password)){
        socket->abort();
        return;
    }


}

bool FundServer::loginValid(QString user, QString password)
{
    // TODO: check the login
    return user=="root" && password=="";
}
