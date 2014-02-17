#ifndef TRANSLATIONMANAGER_H
#define TRANSLATIONMANAGER_H

#include <QMap>

class TranslationsLang;

class TranslationManager
{
public:
    TranslationManager();
    ~TranslationManager();

    bool loadConfig(QString filename);

    void setDefaultLang(TranslationsLang* lang);
    void setDefaultLang(QString lang_code);
    TranslationsLang* getDefaultLang();

    void addLang(TranslationsLang* lang);
    void removeLang(QString lang_code);

    TranslationsLang* getLang(QString lang_code);
    void setLang(QString lang_code, TranslationsLang *lang);

private:
    TranslationsLang* _defaultLang;
    QMap<QString, TranslationsLang*> _translations;
};

#endif // TRANSLATIONMANAGER_H
