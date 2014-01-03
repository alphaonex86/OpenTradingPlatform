#include <QCoreApplication>

#include "fundserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FundServer server;
    server.startServer(QHostAddress::Any, 64542);
    return a.exec();
}
