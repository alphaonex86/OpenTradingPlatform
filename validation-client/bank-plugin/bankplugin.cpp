#include "bankplugin.h"

BankPlugin::BankPlugin(QObject *parent):
    QObject(parent)
{
}

BankPlugin::~BankPlugin()
{

}

QList<Transaction> BankPlugin::getTransactions(const quint32 &page) const
{
    Q_UNUSED(page);
    return QList<Transaction>();
}
bool BankPlugin::deposit(double amount,const QString &destination,const QString &comment)
{
    Q_UNUSED(amount);
    Q_UNUSED(destination);
    Q_UNUSED(comment);
    return false;
}
