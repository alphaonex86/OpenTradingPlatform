#ifndef REQUESTSELL_H
#define REQUESTSELL_H

#include "request.h"

class RequestSell : public Request
{
public:
    RequestSell();
    ~RequestSell();

    bool handle(Client* cl, QJsonObject arg);
    QString getName();
};

#endif // REQUESTSELL_H
