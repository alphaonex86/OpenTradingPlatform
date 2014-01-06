#ifndef FUNDSCONNECTION_H
#define FUNDSCONNECTION_H

#define PACKET_TIMEOUT 5000

#include <QObject>

class QTcpSocket;

class fundsClient: public QObject
{
    Q_OBJECT

public:
    explicit fundsClient(QObject *parent = 0);
    explicit fundsClient(QTcpSocket* socket, QObject *parent = 0);

    virtual ~fundsClient();

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

    /**
     * @return Packet id or -1 if no packet is being process
     */
    void getCurrentPacketId();

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
     * @brief Emit a signal when a packet or something is misunderstand
     */
    void corruptedClient();

private:
    qint16 packetId;

    // The socket used
    QTcpSocket* socket;
};

#endif // FUNDSCONNECTION_H
