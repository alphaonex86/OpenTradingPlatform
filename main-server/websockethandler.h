#ifndef WEBSOCKETHANDLE_H
#define WEBSOCKETHANDLE_H

#include <QObject>

#include "QtWebSocket/QWsServer.h"
#include "QtWebSocket/QWsSocket.h"

#include "sqldata.h"
#include "sqlhandler.h"
#include "client.h"

#include "Request/request.h"

class QSettings;
class TranslationManager;

class WebsocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebsocketHandler(QObject *parent = 0);

    /**
     * @brief createRequest generate a list of available request
     */
    void createRequest();

    /**
     * @brief start a server for Websocket
     * @param port 8080 usually
     * @param protocol Protocol used with WebSocket
     */
    void startServer(int port, QtWebsocket::Protocol protocol);

    /**
     * @brief set the sql handler who will perform request
     * @param handler the sql handler
     */
    void setSqlHandler(SqlHandler* handler);

    /**
     * @brief get the sql handler who will perform request
     * @return the sql handler
     * @see setSqlHandler
     */
    SqlHandler* getSqlHandler();

    void setTranslationManager(TranslationManager* langManager);
    TranslationManager* getTranslationManager();

signals:

public slots:
    /**
     * @brief Called when there is a new Websocket connection
     */
    void processNewConnection();

    /**
     * @brief On receive a new message
     * @note will be reworked
     * @param message
     */
    void processMessage(QString message);

    /**
     * @brief testing stuff
     * @param elapsedTime
     */
    void processPong(quint64 elapsedTime);

    /**
     * @brief webSocket disconnected
     * @note will be reworked
     */
    void socketDisconnected();

protected:
    /**
     * @brief insertClient
     * @param cl
     * @note WIP
     */
    void insertClient(Client* cl);

private:
    /**
     * @brief add a request to the list
     * @param r the request
     */
    void addRequest(Request* r);


    /**
     * @brief sql handler
     * @see setSqlHandler
     * @see getSqlHandler
     */
    SqlHandler* sql;

    /**
     * @brief Configuration (object)
     */
    QSettings* config;

    /**
     * @brief The server for web socket
     */
    QtWebsocket::QWsServer* server;

    /**
     * @brief Used to get fastly client using their id
     */
    QMap<Identity, Client*> clients;

    /**
     * @brief A way to get a client using a id
     */
    QMap<QHostAddress, Client*> clientsAddress;

    /**
     * @brief Associate a request with their name
     */
    QMap<QString, Request*> requestMap;

    TranslationManager* _langManager;
};

#endif // WEBSOCKETHANDLE_H
