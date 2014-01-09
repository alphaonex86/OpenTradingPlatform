#include "requestlang.h"

#include "translationmanager.h"
#include "client.h"

RequestLang::RequestLang(TranslationManager* langManager):
    _manager(langManager)
{
}

RequestLang::~RequestLang()
{
}

QString RequestLang::getName()
{
    return "lang";
}

bool RequestLang::handle(Client *cl, QJsonObject arg)
{
    if(cl == NULL || arg.size()!=2 || !arg.contains("lang")){
        throw InvalidRequestException();
    }

    TranslationsLang* lang = _manager->getLang(arg.value("lang").toString());

    if(lang == NULL){
        return false;
    }

    cl->setLang(lang);
    return true;
}
