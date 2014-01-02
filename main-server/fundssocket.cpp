#include "fundssocket.h"

#include <QByteArray>

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

void FundsSocket::sendConnectionData(QString login, QString password)
{
    if(this->socket->state() == QTcpSocket::BoundState){
        this->writeString(login);
        this->writeString(password);
    }else{
        this->login = login;
        this->password = password;
    }
}

void FundsSocket::onConnected()
{
    if(!this->login.isEmpty() && !this->password.isEmpty()){
        this->writeString(this->login);
        this->writeString(this->password);
        this->login = QString();
        this->password = QString();
    }
    qDebug() << "FundsServer::onConnected";
}

void FundsSocket::onDisconnected()
{
    qDebug() << "FundsServer::onDisconnected";
}

void FundsSocket::writeString(QString str)
{
    if(this->socket->state() != QTcpSocket::BoundState)
        qDebug() << "Writing without bound";
    QByteArray arr = str.toUtf8();
    QByteArray sizearr;
    sizearr.append(arr.size());
    this->socket->write(sizearr);
    this->socket->write(arr);
}
