#include <QCoreApplication>
#include "BCWebSocketServer.h"

#include "fundssocket.h"
#include "sqlhandler.h"
#include "translationmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BCWebSocketServer server ( 6000 ) ;

    TranslationManager* langManager = new TranslationManager();
    langManager->loadConfig("lang.ini");

    FundsSocket* socket = new FundsSocket();
    socket->loadConfig("config.ini");

    SqlHandler* sqlHandler = new SqlHandler();
    sqlHandler->loadConfig("config.ini");

   Q_UNUSED( server ) ;

    return a.exec();
}
