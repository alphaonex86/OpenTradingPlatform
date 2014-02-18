#ifndef BANKINTERFACE_H
#define BANKINTERFACE_H

/**
 * @brief The Interface required to communicate with the bank
 * @note [WIP] used by plugin
 */
#include <QList>
#include <QString>
#include <QDate>

struct Transaction
{
    QString uniqueIdentifier;
    QString source;
    QString label;
    QDate date;
};

class BankInterface
{
public slots:
    virtual QList<Transaction> getTransactions(const quint32 &page) const = 0;
    virtual bool deposit(double amount,const QString &destination,const QString &comment) = 0;
};

Q_DECLARE_INTERFACE(BankInterface, "org.openTradingPlatform.plugin.BankInterface")

#endif // BANKINTERFACE_H
