#include <QDebug>

#include "requestsell.h"

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
    if(cl == NULL || arg.size()!=4){
        // Require login and 3 argument
        throw InvalidRequestException();
    }
    qDebug() << "sell";
    return true;
}
