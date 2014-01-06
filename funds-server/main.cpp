#include <QCoreApplication>
#include <QDir>

#include "fundserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FundServer server;

    server.loadConfig( // load the conf.ini in the current folder
                QDir::toNativeSeparators(a.applicationDirPath() + "/conf.ini")
            );

    return a.exec();
}
