#ifndef FUNDSERVER_H
#define FUNDSERVER_H

#include <QTcpServer>

class FundServer: public QObject
{
    Q_OBJECT

public:


    FundServer();

    void startServer(int port);

private:
    QTcpServer* server;

public slots:
    void on_newConnection();
};

#endif // FUNDSERVER_H
