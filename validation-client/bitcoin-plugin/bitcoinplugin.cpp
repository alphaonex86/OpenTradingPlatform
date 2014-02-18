#include "bitcoinplugin.h"

BitcoinPlugin::BitcoinPlugin(QObject *parent) :
    QObject(parent)
{
}

BitcoinPlugin::~BitcoinPlugin()
{

}

bool BitcoinPlugin::working()
{
    return false;
}

/*symbol display*/
QString BitcoinPlugin::getSymbol() const
{
    return QStringLiteral("BTC");
}

/*unit letter code, 3 letter code*/
QString BitcoinPlugin::getCurrencyCode() const
{
    return QStringLiteral("BTC");
}

QString BitcoinPlugin::getName() const
{
    return QStringLiteral("Bitcoin");
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

