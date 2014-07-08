#ifndef BCWEBSOCKETSERVER_H
#define BCWEBSOCKETSERVER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtNetwork/QSslError>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

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

class BCWebSocketServer : public QObject
{
    Q_OBJECT
public:
    enum Right {
                Buy = VALIDATED_RIGHT,
                Sell = VALIDATED_RIGHT,
                Connect = DEFAULT_RIGHT,
                Disconnect = DEFAULT_RIGHT
               };

//    explicit Client(QObject *parent = 0);
//    explicit Client(const ClientData &data, QObject *parent = 0);

    bool isLogged();
    void logIn();
    void logOut();

    TranslationsLang* getLang();
    void setLang(TranslationsLang* lang);

    bool needDelete();

    bool hasRight(Right r);

    explicit BCWebSocketServer(quint16 port, QObject *parent = Q_NULLPTR);
    virtual ~BCWebSocketServer();

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();
    void onSslErrors(const QList<QSslError> &errors);

private:
    QWebSocketServer *m_pWebSocketServer;
    QList<QWebSocket *> m_clients;
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
     * @brief need to be deleted
     */
    bool _needDelete;
};

#endif // BCWEBSOCKETSERVER_H
