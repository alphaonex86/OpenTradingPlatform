#include <QDebug>

#include "requestbuy.h"

#include "..\BCWebSocketServer.h"

RequestBuy::RequestBuy()
{
}

RequestBuy::~RequestBuy()
{
}

QString RequestBuy::getName()
{
    return "buy";
}

bool RequestBuy::handle(BCWebSocketServer *cl, QJsonObject arg)
{
    if((cl == NULL || !cl->hasRight(BCWebSocketServer::Buy) ) || arg.size()!=4){
        // Require login and 3 argument
        throw InvalidRequestException();
    }
    qDebug() << "buy";
    return true;
}
