#ifndef BANKPLUGIN_H
#define BANKPLUGIN_H

#include <QObject>

#include "../BankInterface.h"

class BankPlugin : public QObject, public BankInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.openTradingPlatform.plugin.BankInterface" FILE "BankPlugin.json")
    Q_INTERFACES(BankInterface)

public:
    BankPlugin(QObject *parent = 0);
    ~BankPlugin();
public slots:
    virtual QList<Transaction> getTransactions(const quint32 &page) const;
    virtual bool deposit(double amount,const QString &destination,const QString &comment);
};

#endif // BANKPLUGIN_H
