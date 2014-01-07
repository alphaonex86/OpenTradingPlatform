#ifndef WEBSOCKETHANDLE_H
#define WEBSOCKETHANDLE_H

#include <QObject>

#include "QtWebSocket/QWsServer.h"
#include "QtWebSocket/QWsSocket.h"

#include "sqldata.h"
#include "client.h"
#include "Request/request.h"

class WebsocketHandle : public QObject
{
    Q_OBJECT
public:
    explicit WebsocketHandle(QObject *parent = 0);

    void startServer(int port, QtWebsocket::Protocol protocol);

    void createRequest();

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

    QtWebsocket::QWsServer* server;
    QMap<Identity, Client*> clients; // id
    QMap<QHostAddress, Client*> clientsAddress; // id
    QMap<QString, Request*> requestMap; // id
};

#endif // WEBSOCKETHANDLE_H
