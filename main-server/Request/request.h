#ifndef REQUEST_H
#define REQUEST_H

#include <QJsonObject>
#include <QString>

class Client;

class Request
{
public:

    virtual ~Request(){}

    /**
     * @brief Handle a request
     * @param cl Client who request
     * @param arg Command and argument
     * @return true, or false if an error happend
     */
    virtual bool handle(Client* cl, QJsonObject arg) = 0;

    /**
     * @brief Used to find the name of the request
     * @return The request's name
     */
    virtual QString getName() = 0;
};

#endif // REQUEST_H
