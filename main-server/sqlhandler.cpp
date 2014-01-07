#include "sqlhandler.h"

SqlHandler::SqlHandler()
{
}

ClientData SqlHandler::getClient(QString login, QString password)
{
    ClientData data;

    // login and fetch data here
    data.id = 1;
    data.login = login;
    data.password = password;

    return data;
}
