#include <QTcpSocket>

#include "fundsclient.h"

fundsClient::fundsClient(QObject *parent):
    QObject(parent)
{
    this->socket = NULL;
}

fundsClient::fundsClient(QTcpSocket* socket, QObject *parent):
    QObject(parent)
{
    this->setSocket(socket);
}

fundsClient::~fundsClient()
{
    delete this->socket;
}

// SLOTS
void fundsClient::abort(){
    this->socket->abort();
}

void fundsClient::read(){
    // Ignore, already processing
    if(this->packetId != -1)
        return;

    if(this->socket->bytesAvailable() == 0)
    {
        qWarning() << "fundsClient::read() called without bytes Available to be read";
    }

    // Read the first bytes to know the packet id
    QByteArray id = this->socket->read(1);
    this->packetId = id[0];

    /// @todo seek the data and parse the packet

    // reset
    this->packetId = 0;

    if(this->socket->bytesAvailable() > 0){
        // read next packet
        this->read();
    }
}

// SETTER and GETTER
void fundsClient::setSocket(QTcpSocket* socket)
{
    connect(socket, SIGNAL(readyRead()), this, SLOT(abort()) );
    this->socket = socket;
}

QTcpSocket* fundsClient::getSocket()
{
    return this->socket;
}
