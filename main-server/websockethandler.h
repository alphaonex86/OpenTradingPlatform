#ifndef WEBSOCKETHANDLE_H
#define WEBSOCKETHANDLE_H

#include <QObject>

#include "QtWebSocket/QWsServer.h"
#include "QtWebSocket/QWsSocket.h"

#include "sqldata.h"
#include "sqlhandler.h"
#include "client.h"

#include "Request/request.h"

class WebsocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebsocketHandler(QObject *parent = 0);

    void createRequest();
    void startServer(int port, QtWebsocket::Protocol protocol);

    void setSqlHandler(SqlHandler* handler);
    SqlHandler* getSqlHandler();

signals:

public slots:
    void processNewConnection();
    void processMessage(QString message);
    void processPong(quint64 elapsedTime);
    void socketDisconnected();

protected:
    void insertClient(Client* cl);

private:
    void addRequest(Request* r);

    SqlHandler* sql;

    QtWebsocket::QWsServer* server;
    QMap<Identity, Client*> clients;
    QMap<QHostAddress, Client*> clientsAddress;
    QMap<QString, Request*> requestMap;
};

#endif // WEBSOCKETHANDLE_H
