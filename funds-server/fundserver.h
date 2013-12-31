#ifndef FUNDSERVER_H
#define FUNDSERVER_H

#include <QTcpServer>

class FundServer: public QObject
{
    Q_OBJECT

public:
    FundServer();

    bool startServer(int port);
    QString readString(QTcpSocket* socket);
    bool loginValid(QString user, QString password);
private:
    QTcpServer* server;
    void askNewConnection(QTcpSocket* socket);

public slots:
    void onNewConnection();
};

#endif // FUNDSERVER_H
