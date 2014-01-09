#ifndef FUNDSCONNECTION_H
#define FUNDSCONNECTION_H

#include <QObject>

class QTcpSocket;
class FundServer;

/**
 * @brief The represente one socket/client connected to the server
 */
class FundsClient: public QObject
{
    Q_OBJECT

public:
    explicit FundsClient(FundServer* server,QObject *parent = 0);
    explicit FundsClient(FundServer* server,QTcpSocket* socket, QObject *parent = 0);

    virtual ~FundsClient();

    // setter and getter

    /**
     * @brief Set and connect the client, allowing access to the server (indirectly)
     * @param socket The client's socket
     */
    void setSocket(QTcpSocket* socket);

    /**
     * @return Return the client socket
     */
    QTcpSocket* getSocket();

public slots:

    /**
     * @brief Abort the connection with the client
     */
    void abort();

    /**
     * @brief Called when there is data to be read
     */
    void read();

signals:

    /**
     * @brief Emit a signal when a command or something is misunderstand
     */
    void corruptedClient();

private:
    bool reading;

    void invalidCommand();

    // Command available
    bool buy(QStringList arg);
    bool sell(QStringList arg);

    // The socket used
    QTcpSocket* socket;

    // Main server
    FundServer* server;
};

#endif // FUNDSCONNECTION_H
