#include "bankplugin.h"

BankPlugin::BankPlugin(QObject *parent):
    QObject(parent)
{
}

BankPlugin::~BankPlugin()
{

}

bool BankPlugin::withdraw(double amount)
{
    return amount > 0;
}

bool BankPlugin::deposit(double amount)
{
    return amount > 0;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(BankPlugin, BankPlugin)
#endif // QT_VERSION < 0x050000
