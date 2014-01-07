#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QList>

#include "QtWebsocket/QWsSocket.h"

#include "sqldata.h"

#define MAX_CLIENT_SOCKET 2
#define MAX_CLIENT_IP 1

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    explicit Client(const ClientData &data, QObject *parent = 0);

signals:

public slots:

private:
    ClientData data;
    QList<QtWebsocket::QWsSocket*> sockets;
};

#endif // CLIENT_H
