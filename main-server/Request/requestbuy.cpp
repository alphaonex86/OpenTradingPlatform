#include <QDebug>

#include "requestbuy.h"

#include "client.h"

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

bool RequestBuy::handle(Client *cl, QJsonObject arg)
{
    if((cl == NULL || !cl->hasRight(Client::Buy) ) || arg.size()!=4){
        // Require login and 3 argument
        throw InvalidRequestException();
    }
    qDebug() << "sell";
    return true;
}
