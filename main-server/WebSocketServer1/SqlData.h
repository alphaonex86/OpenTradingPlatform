/**************************************
 * Author: rrfvtgb                    *
 *                                    *
 * Used to represent the SQL database *
 **************************************/
#ifndef SQLDATA_H
#define SQLDATA_H

#include <Qt>
#include <QString>



/**
 * @brief For ids
 */
typedef quint64 Identity;

/**
 * @brief The Client's representation in database
 */
struct ClientData{
    Identity id;
    QString login;
    QString password;
    QString emailConfirmId;
    bool validated;
    int rank;
};

#endif // SQLDATA_H
