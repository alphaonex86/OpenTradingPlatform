#ifndef SQLHANDLER_H
#define SQLHANDLER_H

#include <QException>

#include "sqldata.h"

class QSqlDatabase;

class InvalidInputException: public QException
{
    void raise() const { throw *this; }
    InvalidInputException *clone() const { return new InvalidInputException(*this); }
};

class SqlHandler
{
public:
    SqlHandler();

    bool loadConfig(QString filename);

    ClientData getClient(QString login, QString password);

private:
    QString encodePassword(QString password);
    QSqlDatabase* database;
};

#endif // SQLHANDLER_H
