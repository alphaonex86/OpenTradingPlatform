#ifndef FUNDSSOCKET_H
#define FUNDSSOCKET_H

#include <QTcpSocket>

class FundsSocket: public QObject
{
    Q_OBJECT
public:
    FundsSocket();

    void connectToHost(const QHostAddress &address, quint16 port);
    void sendConnectionData(QString login, QString password);

signals:
    void onError();

public slots:
    void onConnected();
    void onDisconnected();

private:
    void writeString(QString str);

    QTcpSocket* socket;
    QString login;
    QString password;

};

#endif // FUNDSSOCKET_H
