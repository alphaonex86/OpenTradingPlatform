#ifndef BANKPLUGIN_H
#define BANKPLUGIN_H

#include <QObject>

#include "../funds-server/bitcoininterface.h"

class BitcoinPlugin : public QObject, public BitcoinInterface
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.openTradingPlatform.plugin.bitcoin.interface" FILE "BitcoinPlugin.json")
#endif // QT_VERSION >= 0x050000
    Q_INTERFACES(BitcoinInterface)

public:
    BitcoinPlugin(QObject *parent = 0);

    ~BitcoinPlugin();

public slots:
    bool sellBitcoin( double bitcoinOwned, double quantity, double price );
};

#endif // BANKPLUGIN_H
