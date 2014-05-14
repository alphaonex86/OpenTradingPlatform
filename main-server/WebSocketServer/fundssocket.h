#ifndef FUNDSSOCKET_H
#define FUNDSSOCKET_H

#include <QObject>

class QHostAddress;
class QTcpSocket;

class FundsSocket: public QObject
{
    Q_OBJECT
public:
    FundsSocket();

    /**
     * @brief loadConfig load the config required to connect to the funds server
     * @param filename The path of the config file
     * @return If the config loaded correctly
     */
    bool loadConfig(QString filename);

    /**
     * @brief connectToHost Etablish a connection between the main server and the funds server
     * @param address Address of the Funds-server
     * @param port Port used.
     */
    void connectToHost(const QHostAddress &address, quint16 port);

signals:
    /**
     * @brief onError Signal emited when the connection to the fund server can't be etablish
     */
    void onError();

public slots:
    /**
     * @brief onConnected When TcpSocket is connected
     */
    void onConnected();

    /**
     * @brief onDisconnected When TcpSocket is disconnected
     */
    void onDisconnected();

private:
    /**
     * @brief writeString Send a string to the fund server (a request)
     * @param str Request which is in need to be send
     */
    void writeString(QString str);

    /**
     * @brief socket TCP Connection between funds-server and main-server
     */
    QTcpSocket* socket;

};

#endif // FUNDSSOCKET_H
