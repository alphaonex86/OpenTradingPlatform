#include <QCoreApplication>
#include <QDir>

#include "fundserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FundServer server;

    server.loadConfig("/conf.ini");

    return a.exec();
}
