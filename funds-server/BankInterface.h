#ifndef BANKINTERFACE_H
#define BANKINTERFACE_H

// TODO: create a class for it
class Account;

class BankInterface
{
public:
    virtual ~BankInterface();

    virtual bool withdraw(double amount);
    virtual bool deposit(double amount);
};

Q_DECLARE_INTERFACE(BankInterface, "org.openTradingPlatform.bank.interface")

#endif // BANKINTERFACE_H
