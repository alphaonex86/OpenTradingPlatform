#ifndef BITCOININTERFACE_H
#define BITCOININTERFACE_H

/**
 * @brief The Interface required to make bitcoin wallet
 * @note [WIP] used by plugin
 */
class CryptoCurrencyInterface
{
public slots:
    virtual double getBitcoinFunds(const QString &address) const = 0;
    /// \return empty is failed
    virtual QString sendBitcoinFunds(const QString &sourceAddress,const QString &destinationAddress,const double &value) = 0;
};

Q_DECLARE_INTERFACE(CryptoCurrencyInterface, "org.openTradingPlatform.plugin.CryptoCurrencyInterface")

#endif // BITCOININTERFACE_H
