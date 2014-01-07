#include <QDebug>

#include "requestrefresh.h"

RequestRefresh::RequestRefresh(QObject *parent) :
    QObject(parent)
{
}

RequestRefresh::~RequestRefresh()
{
}

QString RequestRefresh::getName()
{
    return "refresh";
}

bool RequestRefresh::handle(Client *cl, QJsonObject arg)
{
    if(cl == NULL && arg.size()==1){
    }
    qDebug() << "Refresh";
    return true;
}
