#ifndef BITCOININTERFACE_H
#define BITCOININTERFACE_H

class BitcoinInterface
{
public:
    virtual ~BitcoinInterface();
};

Q_DECLARE_INTERFACE(BitcoinInterface, "org.openTradingPlatform.bitcoin.interface")

#endif // BITCOININTERFACE_H
