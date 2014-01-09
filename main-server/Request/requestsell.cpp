#include <QDebug>

#include "requestsell.h"

#include "client.h"

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

bool RequestSell::handle(Client *cl, QJsonObject arg)
{
    if((cl == NULL || !cl->isLogged()) || arg.size()!=4){
        // Require login and 3 argument
        throw InvalidRequestException();
    }
    qDebug() << "sell";
    return true;
}
