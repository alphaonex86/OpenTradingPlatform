#ifndef TRANSLATIONSLANG_H
#define TRANSLATIONSLANG_H

#include <QMap>

class QSettings;

class TranslationsLang
{
public:
    TranslationsLang();
    TranslationsLang(QString path, QString code = QString());

    bool loadConfig(QString path);

    QString getString(const QString &key ) const;
    void setString(const QString &key, const QString &value);

    QString getCode();
    /**
     * @brief change the lang's code
     * @param code the new lang's code
     * @note do not use outside of TranslationManager
     */
    void setCode(QString code);

private:
    QString _code;
    QMap<QString, QString> _translation;
};

#endif // TRANSLATIONSLANG_H
