#include <QSettings>
#include <QDebug>

#include "translationslang.h"

#include "translationmanager.h"

TranslationManager::TranslationManager():
    _defaultLang(NULL)
{
}

TranslationManager::~TranslationManager()
{
    TranslationsLang *lang = NULL;
    foreach(lang, _translations)
    {
        delete lang;
    }
}

bool TranslationManager::loadConfig(QString filename)
{
    QSettings* config = new QSettings(filename, QSettings::IniFormat);

    if(config->status() != QSettings::NoError)
    {
        delete config;
        return false;
    }

    QString code;
    QString filepath;

    qDebug() << "Loading all lang";

    foreach(code, config->allKeys())
    {
        filepath = config->value(code).toString();

        TranslationsLang* lang = new TranslationsLang();

        if(lang->loadConfig(filepath))
        {
            lang->setCode(code);
            this->addLang(lang);

            qDebug() << "Lang loaded: " << code;

        }else{
            qWarning() << "Invalid lang config for " << code;
            delete lang;
        }
    }

    delete config;
    return true;
}

void TranslationManager::setDefaultLang(TranslationsLang* lang)
{
    if(_translations.contains(lang->getCode())){
        qWarning() << "Default lang changed without being in the list";
    }
    _defaultLang = lang;
}

void TranslationManager::setDefaultLang(QString lang_code)
{
    if(_translations.contains(lang_code)){
        qWarning() << "Default lang not found in the list";
    }else{
        _defaultLang = this->getLang(lang_code);
    }
}

TranslationsLang* TranslationManager::getDefaultLang()
{
    return _defaultLang;
}

void TranslationManager::addLang(TranslationsLang *lang)
{
    _translations.insert(lang->getCode(), lang);
    if(_defaultLang == NULL)
    {
        _defaultLang = lang;
    }
}

void TranslationManager::removeLang(QString lang_code)
{
    _translations.remove(lang_code);
}

TranslationsLang* TranslationManager::getLang(QString lang_code)
{
    if(_translations.contains(lang_code)){
        return _translations.value(lang_code);
    }else{
        return NULL;
    }
}

void TranslationManager::setLang(QString lang_code, TranslationsLang *lang)
{
    _translations.insert(lang_code, lang);
}
