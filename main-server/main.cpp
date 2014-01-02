#include <QCoreApplication>
#include <QHostAddress>

#include "fundssocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FundsSocket* socket = new FundsSocket();
    socket->connectToHost(QHostAddress::LocalHost, 64542);
    socket->sendConnectionData("kperh","rhtkpo");

    return a.exec();
}
