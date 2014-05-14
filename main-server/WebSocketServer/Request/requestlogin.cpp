#include "requestlogin.h"

#include "..\BCWebSocketServer.h"

RequestLogin::RequestLogin()
{
}

QString RequestLogin::getName()
{
    return "login";
}

bool RequestLogin::handle(BCWebSocketServer *cl, QJsonObject arg)
{
    if((cl == NULL || cl->isLogged() ) || arg.size()!=3){
        // Require login and 3 argument
        throw InvalidRequestException();
    }

    // todo: login here

    return true;
}
