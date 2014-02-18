#include "bitcoinplugin.h"

BitcoinPlugin::BitcoinPlugin(QObject *parent) :
    QObject(parent)
{
}

BitcoinPlugin::~BitcoinPlugin()
{

}

double BitcoinPlugin::getBitcoinFunds(const QString &address) const
{
    Q_UNUSED(address);
    return 0;
}

QString BitcoinPlugin::sendBitcoinFunds(const QString &sourceAddress,const QString &destinationAddress,const double &value)
{
    Q_UNUSED(sourceAddress);
    Q_UNUSED(destinationAddress);
    Q_UNUSED(value);
    return QString();
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(BitcoinPlugin, BitcoinPlugin)
#endif // QT_VERSION < 0x050000
