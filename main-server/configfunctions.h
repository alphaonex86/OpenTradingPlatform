#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class QVariant;
class QSettings;
class QString;

// return a QVariant from a config file, and set it if not found
QVariant getConfigValue(QSettings* config, QString &key, QVariant defaultValue = QVariant());

// return a QString from a config file, and set it if not found
QString getConfigStringValue(QSettings* config, const char* key, const char* defaultValue);

#endif // FUNCTIONS_H
