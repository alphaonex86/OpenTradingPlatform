#include <QSettings>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QCryptographicHash>

#include "sqlhandler.h"

#include "configfunctions.h"

QSqlDatabase* SqlHandler::database = NULL ;

SqlHandler::SqlHandler()
{
}

QSqlDatabase * SqlHandler::GetDatabaseHandler( )
{
    return database ;
}

bool SqlHandler::loadConfig(QString filename)
{
    QSettings* config = new QSettings(filename, QSettings::IniFormat );

    if(config->status() != QSettings::NoError){
        qWarning() << "Unable to load config file";
        return false;
    }

    // Open a new database connection with data in the config file
    database =  new QSqlDatabase(QSqlDatabase::addDatabase(getConfigStringValue(config, "database/type", "QMYSQL")));

    database->setConnectOptions(getConfigStringValue(config, "database/connectOptions", ""));
    database->setHostName(      getConfigStringValue(config, "database/host",           "localhost"));
    database->setDatabaseName(  getConfigStringValue(config, "database/database",       "bitcoinexchange"));
    database->setUserName(      getConfigStringValue(config, "database/user",           "root"));
    database->setPassword(      getConfigStringValue(config, "database/password",       "mysql"));
    database->setPort( QString ( getConfigStringValue(config, "database/port",       "3307" ) ).toInt( ) ) ;

    if(database->open())
    {
        // Default Table file
        QFile script(":/script/database/database.sql"); //To be Changed, when verified manually

        QSqlQuery* query = new QSqlQuery(script.readAll(), *database);
        query->exec();
        return true;
    }
    else{
        return false;
    }
}

ClientData SqlHandler::getClient(QString login, QString password)
{
    ClientData data;

    QSqlQuery* query = new QSqlQuery("SELECT * FROM Client WHERE login = :login AND password = :password",*database);
    query->bindValue("login", login);
    query->bindValue("password", encodePassword(password));

    if(!query->exec() || query->size() != 1)
    {
        throw SqlInvalidInputException();
    }

    query->first();
    data.id = query->value("id").toLongLong();
    data.login = login;
    data.password = password;

    return data;
}

QString SqlHandler::encodePassword(QString password)
{
    return QString::fromUtf8(
                QCryptographicHash::hash(
                    password.toUtf8(),
                    QCryptographicHash::Sha3_512
                )
            );
}
