#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QList>

#include "QtWebsocket/QWsSocket.h"

#include "sqldata.h"

/**
 * @brief Maximum socket by one client
 */
#define MAX_CLIENT_SOCKET 2

/**
 * @brief How many IP allowed by one client
 */
#define MAX_CLIENT_IP 1

/**
 * @brief Class containing all the active socket and the data required by one client
 * @note Work in progress class
 */
class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    explicit Client(const ClientData &data, QObject *parent = 0);

    bool isLogged();
    void logIn();
    void logOut();
signals:

public slots:

private:
    /**
     * @brief data about the client
     */
    ClientData data;

    /**
     * @brief If client is logged
     */
    bool _logged;

    /**
     * @brief all socket used by one client
     */
    QList<QtWebsocket::QWsSocket*> sockets;
};

#endif // CLIENT_H
