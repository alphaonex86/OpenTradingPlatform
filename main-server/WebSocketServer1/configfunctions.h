#ifndef FUNCTIONS_H
#define FUNCTIONS_H

class QVariant;
class QSettings;
class QString;

/**
 * @brief return a QVariant from a config file, and set it if not found
 * @param config The configuration object
 * @param key The name of the setting
 * @param defaultValue The value who will be register if there is no setting with that name (yet)
 * @return The Value of setting at end of the functions
 */
QVariant getConfigValue(QSettings* config, QString &key, QVariant defaultValue = QVariant());

// return a QString from a config file, and set it if not found
/**
 * @brief Overloaded function
 * @param config The configuration object
 * @param key The name of the setting
 * @param defaultValue The default string who will be register if there is no setting with that name (yet)
 * @see getConfigValue
 * @return The Value of setting at end of the functions
 */
QString getConfigStringValue(QSettings* config, const char* key, const char* defaultValue);

#endif // FUNCTIONS_H
