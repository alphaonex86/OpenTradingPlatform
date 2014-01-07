#ifndef SQLDATA_H
#define SQLDATA_H

#include <Qt>
#include <QString>

typedef quint64 Identity;

struct ClientData{
    Identity id;
    QString login;
    QString password;
};

#endif // SQLDATA_H
