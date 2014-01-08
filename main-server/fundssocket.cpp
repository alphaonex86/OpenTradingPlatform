#include <QByteArray>
#include <QTcpSocket>
#include <QSettings>
#include <QHostAddress>

#include "fundssocket.h"

#include "configfunctions.h"

FundsSocket::FundsSocket()
{
    this->socket = new QTcpSocket();
    connect(this->socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(this->socket,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
}

bool FundsSocket::loadConfig(QString filename)
{
    QSettings* config = new QSettings(filename, QSettings::IniFormat);

    if(config->status() != QSettings::NoError){
        qWarning() << "Unable to load config file";
        return false;
    }

    QString address = getConfigStringValue(config, "funds/address", "127.0.0.1");
    quint16 port = getConfigStringValue(config, "funds/port", "6542").toUInt();

    this->connectToHost(QHostAddress(address), port);
    return true;
}

void FundsSocket::connectToHost(const QHostAddress &address, quint16 port)
{
    this->socket->connectToHost(address, port);
}

void FundsSocket::onConnected()
{
    qDebug() << "FundsSocket::onConnected";
}

void FundsSocket::onDisconnected()
{
    qDebug() << "FundsSocket::onDisconnected";
}

void FundsSocket::writeString(QString str)
{
    if(this->socket->state() != QTcpSocket::ConnectedState)
        qDebug() << "Writing without being connected";
    QByteArray arr = str.toUtf8();
    this->socket->write(arr);
}
