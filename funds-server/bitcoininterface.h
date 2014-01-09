#ifndef BITCOININTERFACE_H
#define BITCOININTERFACE_H

/**
 * @brief The Interface required to make bitcoin wallet
 * @note [WIP] used by plugin
 */
class BitcoinInterface
{
public slots:
    virtual bool sellBitcoin( double bitcoinOwned, double quantity, double price ) = 0;
};

Q_DECLARE_INTERFACE(BitcoinInterface, "org.openTradingPlatform.plugin.bitcoin.interface")

#endif // BITCOININTERFACE_H
