#ifndef REQUESTREFRESH_H
#define REQUESTREFRESH_H

#include "request.h"

class RequestRefresh : public Request
{
public:
    RequestRefresh();
    ~RequestRefresh();

    bool handle(BCWebSocketServer* cl, QJsonObject arg);
    QString getName();
};

#endif // REQUESTREFRESH_H
