#ifndef SQLHANDLER_H
#define SQLHANDLER_H

#include <QException>

#include "sqldata.h"

class QSqlDatabase;

/**
 * @brief Exception throw when an invalid input as being detected
 */
class SqlInvalidInputException: public QException
{
    void raise() const { throw *this; }
    SqlInvalidInputException *clone() const { return new SqlInvalidInputException(*this); }
};

class SqlHandler
{
public:
    SqlHandler();

    /**
     * @brief load the config required to connect to the database
     * @param filename The path of the config file
     * @return If the config loaded correctly
     */
    bool loadConfig(QString filename);

    /**
     * @brief Connect a client (inside the database), and return his own data
     * @param login the login of the client
     * @param password the password of the client
     * @return When successful, it will return the client data
     * @throw SqlInvalidInputException on invalid login/password
     */
    ClientData getClient(QString login, QString password);

private:
    /**
     * @brief crypt a password, to avoid to save directly them in the database
     * @param password the password to be crypted
     * @return the crypted password
     */
    QString encodePassword(QString password);

    /**
     * @brief The database used by the main server
     */
    QSqlDatabase* database;
};

#endif // SQLHANDLER_H
