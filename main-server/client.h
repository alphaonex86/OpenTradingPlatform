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

/// Rank of client
// No account
#define GUEST_RIGHT 0

// Account not validated
#define DEFAULT_RIGHT 1

// Account Validated
#define VALIDATED_RIGHT 2

// Account with moderator right
#define MODERATOR_RIGHT 3

// Account with admin right/ Dev account
#define ADMIN_RIGHT 4

class TranslationsLang;
class WebsocketHandler;

/**
 * @brief Class containing all the active socket and the data required by one client
 * @note Work in progress class
 */
class Client : public QObject
{
    Q_OBJECT

public:

    enum Right {
                Buy = VALIDATED_RIGHT,
                Sell = VALIDATED_RIGHT,
                Connect = DEFAULT_RIGHT,
                Disconnect = DEFAULT_RIGHT
               };

    explicit Client(QObject *parent = 0);
    explicit Client(const ClientData &data, QObject *parent = 0);

    bool isLogged();
    void logIn();
    void logOut();

    void addSocket(QtWebsocket::QWsSocket *socket);

    WebsocketHandler* getWebsocketHandler();
    void setWebsocketHandler(WebsocketHandler* handler);

    TranslationsLang* getLang();
    void setLang(TranslationsLang* lang);

    bool needDelete();

    bool hasRight(Right r);

signals:
    void frameReceived(QtWebsocket::QWsSocket* socket, QString frame);
    void disconnected(QtWebsocket::QWsSocket* socket);
    void pong(QtWebsocket::QWsSocket* socket, quint64 elaspedTime);

public slots:
    void processMessage(QString frame);
    void socketDisconnected();
    void processPong(quint64 elaspedTime);

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
     * @brief actual lang used by the client
     */
    TranslationsLang* _lang;

    /**
     * @brief all socket used by one client
     */
    QList<QtWebsocket::QWsSocket*> sockets;

    /**
     * @brief Manager of all client using websocket
     */
    WebsocketHandler* _handler;

    /**
     * @brief need to be deleted
     */
    bool _needDelete;
};

#endif // CLIENT_H
