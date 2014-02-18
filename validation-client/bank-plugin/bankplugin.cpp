#include "bankplugin.h"

BankPlugin::BankPlugin(QObject *parent):
    QObject(parent)
{
}

BankPlugin::~BankPlugin()
{
}

bool BankPlugin::working()
{
    return false;
}

/*symbol display*/
QString BankPlugin::getSymbol() const
{
    return QStringLiteral("$");
}

/*unit letter code, 3 letter code*/
QString BankPlugin::getCurrencyCode() const
{
    return QStringLiteral("USD");
}

QString BankPlugin::getName() const
{
    return QStringLiteral("Bank X");
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
