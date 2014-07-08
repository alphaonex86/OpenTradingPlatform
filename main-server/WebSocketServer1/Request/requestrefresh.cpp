#include <QDebug>

#include "requestrefresh.h"

RequestRefresh::RequestRefresh()
{
}

RequestRefresh::~RequestRefresh()
{
}

QString RequestRefresh::getName()
{
    return "refresh";
}

bool RequestRefresh::handle(BCWebSocketServer *cl, QJsonObject arg)
{
    if(cl == NULL && arg.size()==1){
    }
    qDebug() << "Refresh";
    return true;
}
