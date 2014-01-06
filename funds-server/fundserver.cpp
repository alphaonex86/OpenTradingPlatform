#include <QDebug>
#include <QPluginLoader>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QSettings>

#include "bitcoininterface.h"
#include "bankinterface.h"

#include "fundserver.h"

FundServer::FundServer(QObject *parent):
    QObject(parent){
    this->bankPlugin    = new QPluginLoader();
    this->bitcoinPlugin = new QPluginLoader();
}

void FundServer::loadConfig(QString configPath)
{
    // load the config
    QSettings setting(configPath, QSettings::IniFormat);

    // Plugin data
    this->loadPlugin(setting.value("plugin/bitcoin", "plugin/bitcoin.dll").toString(), Bitcoin);
    this->loadPlugin(setting.value("plugin/bank",    "plugin/bank.dll").toString(),    Bank);

    // Connection data
    QHostAddress address = QHostAddress(setting.value("server/acceptedAddress").toString());
    if(address.isNull()){ // Invalid address
        address = QHostAddress::Any;
    }

    quint16 port = setting.value("server/port", 6542).toUInt();

    this->startServer(address, port);
}

bool FundServer::startServer(const QHostAddress &address, quint16 port)
{
    if(!bankPlugin->isLoaded()
            || !bitcoinPlugin->isLoaded()){
        qDebug() << "Plugin aren't loaded";
        return false;
    }

    this->server = new QTcpServer(this);

    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    if (!server->listen(address, port)){
        qDebug() << "Failed to Listen";
        return false;
    }

    qDebug() << "Listening on port " << port;
    return true;
}

void FundServer::onNewConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();
    if(!socket->waitForReadyRead()){
        socket->abort();
    }
}

QString FundServer::readString(QTcpSocket *socket)
{
    // String size
    QByteArray readData = socket->read(1);

    // String data
    return QString::fromUtf8(socket->read(readData[0]));
}

void FundServer::askNewConnection(QTcpSocket* socket)
{
    // A plugin will do the first step

    // If connection success
    if(true){
        connect(socket,SIGNAL(readyRead()), this, SLOT(onNewData()));
    }
}

bool FundServer::loadPlugin(QString path, FundsPluginType type)
{
    QObject* instance = NULL;
    switch (type) {
    case Bitcoin:
        if(!this->loadPluginPrivate(bitcoinPlugin, path))
        {
            return false;
        }

        instance = bitcoinPlugin->instance();

        if(dynamic_cast<BitcoinInterface*>(instance) == NULL)
        {
            this->bitcoinPlugin->unload();
            return false;
        }

        return true;
        break;
    case Bank:
        if(!this->loadPluginPrivate(bankPlugin, path))
            return false;

        instance = bankPlugin->instance();

        if(dynamic_cast<BankInterface*>(instance) == NULL)
        {
            this->bankPlugin->unload();
            return false;
        }

        return true;
        break;
    default:
        qDebug() << "Invalid plugin type";
        break;
    }

    return false;
}

bool FundServer::loadPluginPrivate(QPluginLoader *loader, QString path)
{
    loader->setFileName(path);
    if(loader->load()){
        return true;
    }else{
        qDebug() << "Can't load plugin with path " << path;
        return false;
    }
}
