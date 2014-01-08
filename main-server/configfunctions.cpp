#include <QSettings>
#include <QString>
#include <QVariant>

#include "configfunctions.h"

QVariant getConfigValue(QSettings* config, QString &key, QVariant defaultValue)
{
    if(config->contains(key))
    {
        return config->value(key);
    }
    else{
        config->setValue(key, defaultValue);
        return defaultValue;
    }
}

QString getConfigStringValue(QSettings* config, const char* key, const char* defaultValue)
{
    QString keyString = key;
    return getConfigValue(config, keyString, QVariant(QString(defaultValue))).toString();
}
