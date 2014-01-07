#ifndef REQUESTREFRESH_H
#define REQUESTREFRESH_H

#include <QObject>

#include "request.h"

class RequestRefresh :  public QObject, public Request
{
    Q_OBJECT
public:
    explicit RequestRefresh(QObject *parent = 0);

    ~RequestRefresh();

    bool handle(Client* cl, QJsonObject arg);
    QString getName();
signals:

public slots:

};

#endif // REQUESTREFRESH_H
