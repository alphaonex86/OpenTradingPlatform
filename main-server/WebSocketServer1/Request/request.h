#ifndef REQUEST_H
#define REQUEST_H

#include <QJsonObject>
#include <QString>
#include <QException>

class BCWebSocketServer;

/**
 * @brief Exception throw when an invalid request as being detected
 */
class InvalidRequestException: public QException
{
    void raise() const { throw *this; }
    InvalidRequestException *clone() const { return new InvalidRequestException(*this); }
};


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
    virtual bool handle(BCWebSocketServer* cl, QJsonObject arg) = 0;

    /**
     * @brief Used to find the name of the request
     * @return The request's name
     */
    virtual QString getName() = 0;
};

#endif // REQUEST_H
