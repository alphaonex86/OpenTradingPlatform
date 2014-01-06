#include <QTcpSocket>

#include "fundsclient.h"

FundsClient::FundsClient(FundServer* server, QObject *parent):
    QObject(parent)
{
    this->server = server;
    this->socket = NULL;
}

FundsClient::FundsClient(FundServer* server, QTcpSocket* socket, QObject *parent):
    QObject(parent)
{
    this->server = server;
    this->setSocket(socket);
}

FundsClient::~FundsClient()
{
    delete this->socket;
}

// SLOTS
void FundsClient::abort(){
    this->socket->abort();
}

void FundsClient::read(){
    // Ignore, already processing
    if(this->reading)
        return;

    this->reading = true;

    if(this->socket->bytesAvailable() == 0)
    {
        qWarning() << "fundsClient::read() called without bytes Available to be read";
        this->reading = false;
        return;
    }

    // 1 line = 1 command
    QByteArray line = this->socket->readLine();

    // Command string
    QString cmd = QString(line);

    // Command argument (including command name)
    QStringList arg = cmd.split(' ');

    if(arg.size() < 1){ // Error when parsing the command
        this->invalidCommand();
        return;
    }

    if(arg[0] == "buy"){ // buy bitcoin
        if(!this->buy(arg)){
            return this->invalidCommand();
        }
    }
    else if(arg[0] == "sell"){ // sell bitcoin
        if(!this->sell(arg)){
            return this->invalidCommand();
        }
    }

    // reset
    this->reading = false;

    if(this->socket->bytesAvailable() > 0){
        // read next packet
        this->read();
    }
}

// Command
bool FundsClient::buy(QStringList arg)
{
    /**
     * - Who
     * - Quantity of bitcoin owned
     * - Quantity to sell
     * - Price to sell
     */
    if(arg.size() != 5){
        return false;
    }

    bool ownedOk, quantityOk, priceOk = true;

    quint64 who = arg[1].toInt(&ownedOk);
    double bitcoinOwned = arg[2].toDouble(&ownedOk);
    double quantity = arg[3].toDouble(&quantityOk);
    double price = arg[4].toDouble(&priceOk);

    if(!ownedOk || !quantityOk || !priceOk){
        return false;
    }

    return true;
}

bool FundsClient::sell(QStringList arg)
{
    /**
     * - Who
     * - Quantity of euro owned
     * - Quantity to how many euro to use
     * - Price to buy
     */
    if(arg.size() != 5){
        return false;
    }
    return true;
}

void FundsClient::invalidCommand()
{
    emit corruptedClient();
    this->reading = false;
}

// SETTER and GETTER
void FundsClient::setSocket(QTcpSocket* socket)
{
    connect(socket, SIGNAL(readyRead()), this, SLOT(abort()) );
    this->socket = socket;
}

QTcpSocket* FundsClient::getSocket()
{
    return this->socket;
}
