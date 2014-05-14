#ifndef REQUESTLOGIN_H
#define REQUESTLOGIN_H

#include "request.h"

class RequestLogin : public Request
{
public:
    RequestLogin();

    bool handle(BCWebSocketServer* cl, QJsonObject arg);
    QString getName();
};

#endif // REQUESTLOGIN_H

