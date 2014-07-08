#include <QDebug>

#include "requestsell.h"

#include "..\BCWebSocketServer.h"

RequestSell::RequestSell()
{
}

RequestSell::~RequestSell()
{
}

QString RequestSell::getName()
{
    return "sell";
}

bool RequestSell::handle(BCWebSocketServer *cl, QJsonObject arg)
{
    if((cl == NULL || !cl->hasRight(BCWebSocketServer::Sell)) || arg.size()!=4){
        // Require login and 3 argument
        throw InvalidRequestException();
    }
    qDebug() << "sell";
    return true;
}
