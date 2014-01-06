#include "bitcoinplugin.h"

BitcoinPlugin::BitcoinPlugin(QObject *parent) :
    QObject(parent)
{
}

BitcoinPlugin::~BitcoinPlugin()
{

}

bool BitcoinPlugin::sellBitcoin( double bitcoinOwned, double quantity, double price )
{
    return bitcoinOwned >= quantity && quantity > 0 && price > 0;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(BankPlugin, BankPlugin)
#endif // QT_VERSION < 0x050000
