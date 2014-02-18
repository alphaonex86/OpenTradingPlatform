#ifndef BITCOININTERFACE_H
#define BITCOININTERFACE_H

#include <QPair>

class CryptoCurrencyInterface
{
public:
    virtual bool working() = 0;
    virtual QString getName() const = 0;
    virtual QString getSymbol() const = 0;/*symbol display*/
    virtual QString getCurrencyCode() const = 0;/*unit letter code, 3 letter code*/
    virtual double getBitcoinFunds(const QString &address) const = 0;
    /// \return empty is failed
    virtual QString sendBitcoinFunds(const QString &sourceAddress,const QString &destinationAddress,const double &value) = 0;
};

Q_DECLARE_INTERFACE(CryptoCurrencyInterface, "org.openTradingPlatform.plugin.CryptoCurrencyInterface")

#endif // BITCOININTERFACE_H
