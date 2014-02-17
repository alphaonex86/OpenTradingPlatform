#ifndef REQUESTLOGIN_H
#define REQUESTLOGIN_H

#include "request.h"

class RequestLogin : public Request
{
public:
    RequestLogin();

    bool handle(Client* cl, QJsonObject arg);
    QString getName();
};

#endif // REQUESTLOGIN_H

