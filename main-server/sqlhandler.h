#ifndef SQLHANDLER_H
#define SQLHANDLER_H

#include "sqldata.h"

class SqlHandler
{
public:
    SqlHandler();

    ClientData getClient(QString login, QString password);
};

#endif // SQLHANDLER_H
