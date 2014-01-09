#ifndef REQUESTLANG_H
#define REQUESTLANG_H

#include "request.h"

class TranslationManager;

class RequestLang : public Request
{
public:
    RequestLang(TranslationManager* langManager);
    ~RequestLang();

    bool handle(Client* cl, QJsonObject arg);
    QString getName();

protected:
    TranslationManager* _manager;
};

#endif // REQUESTLANG_H
