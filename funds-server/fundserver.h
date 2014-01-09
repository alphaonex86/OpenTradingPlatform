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

    /**
     * @brief start listening on a port and await client
     * @param address Address accepted
     * @param port port used to connect
     * @return If the server started
     */
    bool startServer(const QHostAddress &address, quint16 port);

    /**
     * @brief load a config file and start the server using the parameters, and load required plugin
     * @param configPath the path to the config's file
     * @see startServer
     */
    void loadConfig(QString configPath);

public slots:
    /**
     * @brief every time a new socket connected to the server, this function is called
     */
    void onNewConnection();

    /**
     * @brief load a plugin using a path
     * @param path the plugin's path
     * @param type which kind of plugin is it
     * @return if the plugin successfuly loaded
     */
    bool loadPlugin(QString path, FundsPluginType type);

protected:
    void askNewConnection(QTcpSocket* socket);

private:
    QTcpServer* server;
    QPluginLoader* bitcoinPlugin;
    QPluginLoader* bankPlugin;
};

#endif // FUNDSERVER_H
