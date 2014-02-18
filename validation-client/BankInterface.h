#ifndef BANKINTERFACE_H
#define BANKINTERFACE_H

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
public:
    virtual bool working() = 0;
    virtual QString getName() const = 0;
    virtual QString getSymbol() const = 0;/*symbol display*/
    virtual QString getCurrencyCode() const = 0;/*unit letter code, 3 letter code*/
    virtual QList<Transaction> getTransactions(const quint32 &page) const = 0;
    virtual bool deposit(double amount,const QString &destination,const QString &comment) = 0;
};

Q_DECLARE_INTERFACE(BankInterface, "org.openTradingPlatform.plugin.BankInterface")

#endif // BANKINTERFACE_H
