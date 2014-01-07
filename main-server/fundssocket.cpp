#include "fundssocket.h"

#include <QByteArray>
#include <QTcpSocket>

FundsSocket::FundsSocket()
{
    this->socket = new QTcpSocket();
    connect(this->socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(this->socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

void FundsSocket::connectToHost(const QHostAddress &address, quint16 port)
{
    this->socket->connectToHost(address, port);
}

void FundsSocket::onConnected()
{
    qDebug() << "FundsServer::onConnected";
}

void FundsSocket::onDisconnected()
{
    qDebug() << "FundsServer::onDisconnected";
}

void FundsSocket::writeString(QString str)
{
    if(this->socket->state() != QTcpSocket::ConnectedState)
        qDebug() << "Writing without bound";
    QByteArray arr = str.toUtf8();
    this->socket->write(arr);
}
