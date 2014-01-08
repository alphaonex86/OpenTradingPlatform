#ifndef BANKPLUGIN_H
#define BANKPLUGIN_H

#include <QObject>

#include "../funds-server/bankinterface.h"

class BankPlugin : public QObject, public BankInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.openTradingPlatform.plugin.bank.interface" FILE "BankPlugin.json")
#endif // QT_VERSION >= 0x050000
    Q_INTERFACES(BankInterface)

public:
    BankPlugin(QObject *parent = 0);

    ~BankPlugin();

public slots:
    bool withdraw(double amount);
    bool deposit(double amount);
};

#endif // BANKPLUGIN_H
