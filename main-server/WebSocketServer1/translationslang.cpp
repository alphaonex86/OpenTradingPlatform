#include <QSettings>
#include <QFile>
#include <QString>
#include <QDebug>

#include "translationslang.h"

TranslationsLang::TranslationsLang()
{
}

TranslationsLang::TranslationsLang(QString path, QString code):
    _code(code)
{
    this->loadConfig(path);
}

bool TranslationsLang::loadConfig(QString path)
{
    this->_translation.clear();

    QSettings* config = new QSettings(path, QSettings::IniFormat);

    if(config->status() != QSettings::NoError)
    {
        delete config;
        return false;
    }

    QString str;
    QString value;
    QFile stringFile;

    foreach(str, config->allKeys()){
        value = config->value(str).toString();
        stringFile.setFileName(value);

        if(stringFile.open(QFile::ReadOnly)){
            this->setString(str,
                            QString::fromUtf8(stringFile.readAll())
            );
        }else{
            this->setString(str, value);
        }
    }

    delete config;
    return true;
}

QString TranslationsLang::getString(const QString &key) const
{
    return this->_translation.value(key);
}

void TranslationsLang::setString(const QString &key, const QString &value)
{
    this->_translation.insert(key, value);
}

QString TranslationsLang::getCode()
{
    return _code;
}

void TranslationsLang::setCode(QString code)
{
    _code = code;
}
