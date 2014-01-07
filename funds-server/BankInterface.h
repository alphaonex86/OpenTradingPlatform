#ifndef BANKINTERFACE_H
#define BANKINTERFACE_H

class BankInterface
{
public slots:
    virtual bool withdraw( double amount ) = 0;
};

Q_DECLARE_INTERFACE(BankInterface, "org.openTradingPlatform.plugin.bank.interface")

#endif // BANKINTERFACE_H
