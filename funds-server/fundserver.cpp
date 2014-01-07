#include <QDebug>
#include <QPluginLoader>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostAddress>
#include <QSettings>

#include "bitcoininterface.h"
#include "bankinterface.h"
#include "fundsclient.h"

#include "fundserver.h"

FundServer::FundServer(QObject *parent):
    QObject(parent){
    this->bankPlugin    = new QPluginLoader();
    this->bitcoinPlugin = new QPluginLoader();
}

QVariant configValue(QSettings &config, const QString &key, const QVariant &defaultValue = QVariant()){
    if(config.contains(key)){
        return config.value(key);
    }

    config.setValue(key, defaultValue);
    return defaultValue;
}

void FundServer::loadConfig(QString configPath)
{
    // load the config
    QSettings setting(configPath, QSettings::IniFormat);

    // Plugin data
    this->loadPlugin(configValue(setting,"plugin/bitcoin", "plugin/bitcoin.dll").toString(), Bitcoin);
    this->loadPlugin(configValue(setting,"plugin/bank",    "plugin/bank.dll").toString(),    Bank);

    // Connection data
    QHostAddress address = QHostAddress(configValue(setting, "server/acceptedAddress", "0.0.0.0").toString());
    if(address.isNull()){ // Invalid address
        address = QHostAddress::Any;
    }

    quint16 port = configValue(setting, "server/port", 6542).toUInt();

    this->startServer(address, port);
}

bool FundServer::startServer(const QHostAddress &address, quint16 port)
{
    if(!bankPlugin->isLoaded()
            || !bitcoinPlugin->isLoaded()){
        qWarning() << "Plugin aren't loaded correctly";
        return false;
    }

    this->server = new QTcpServer(this);

    if (!server->listen(address, port)){
        qDebug() << "Failed to Listen (port used ?)";
        return false;
    }

    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    qDebug() << "Accepted Address"  << address.toString();
    qDebug() << "Listening on port" << port;
    return true;
}

void FundServer::onNewConnection()
{
    QTcpSocket* socket = server->nextPendingConnection();
    if(!socket->waitForReadyRead()){
        socket->abort();
    }else{
        this->askNewConnection(socket);
    }
}

void FundServer::askNewConnection(QTcpSocket* socket)
{
    // Login step here

    // If connection success
    if(true){
        FundsClient* client = new FundsClient(this, socket);
        if(socket->bytesAvailable()!=0){
            client->read();
        }
    }
}

template <class T> bool loadPluginTemplate(QPluginLoader *loader, QString path)
{
    QObject* instance = NULL;
    loader->setFileName(path);
    if(loader->load()){
        instance = loader->instance();
        if(qobject_cast<T>(instance) == NULL)
        {
            loader->unload();
            qDebug() << "Invalid instance" << path;
            return false;
        }
        return true;
    }else{
        qDebug() << "Can't load plugin with path " << path;
        return false;
    }
}

bool FundServer::loadPlugin(QString path, FundsPluginType type)
{
    switch (type) {
    case Bitcoin:
        return loadPluginTemplate<BitcoinInterface*>(bitcoinPlugin, path);
    case Bank:
        return loadPluginTemplate<BankInterface*>(bankPlugin, path);
    default:
        qDebug() << "Invalid plugin type";
        break;
    }

    return false;
}


