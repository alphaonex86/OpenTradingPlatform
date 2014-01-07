#ifndef FUNDSERVER_H
#define FUNDSERVER_H

#include <QObject>

class QTcpServer;
class QTcpSocket;
class QHostAddress;
class QPluginLoader;


class FundServer: public QObject
{
    Q_OBJECT

    // Plugin which may/should be loaded
    enum FundsPluginType { Bank,
                           Bitcoin,
                           Other
                         };
public:
    explicit FundServer(QObject *parent = 0);

    bool startServer(const QHostAddress &address, quint16 port);
    void loadConfig(QString configPath);

public slots:
    void onNewConnection();
    bool loadPlugin(QString path, FundsPluginType type);

protected:
    void askNewConnection(QTcpSocket* socket);

private:
    QTcpServer* server;
    QPluginLoader* bitcoinPlugin;
    QPluginLoader* bankPlugin;
};

#endif // FUNDSERVER_H
