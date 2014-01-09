#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    _logged = false;
    _lang = NULL;
}

bool Client::isLogged()
{
    return _logged;
}

void Client::logIn()
{
    // temporary
    _logged = true;
}

void Client::logOut()
{
    // temporary
    _logged = false;
}

TranslationsLang* Client::getLang()
{
    return _lang;
}

void Client::setLang(TranslationsLang* lang)
{
    _lang = lang;
}

void Client::addSocket(QtWebsocket::QWsSocket *socket)
{
    sockets << socket;

    connect(socket, SIGNAL(frameReceived(QString)), this, SLOT(processMessage(QString)));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(socket, SIGNAL(pong(quint64)), this, SLOT(processPong(quint64)));
}

void Client::processMessage(QString frame)
{
    QtWebsocket::QWsSocket* socket = dynamic_cast<QtWebsocket::QWsSocket*>(sender());
    if(socket && !_needDelete){
        emit frameReceived(socket, frame);
    }
}

void Client::socketDisconnected()
{
    QtWebsocket::QWsSocket* socket = dynamic_cast<QtWebsocket::QWsSocket*>(sender());
    if(socket && !_needDelete){
        emit disconnected(socket);
    }
}

void Client::processPong(quint64 elaspedTime)
{
    QtWebsocket::QWsSocket* socket = dynamic_cast<QtWebsocket::QWsSocket*>(sender());
    if(socket && !_needDelete){
        emit pong(socket, elaspedTime);
    }
}

void Client::setWebsocketHandler(WebsocketHandler *handler)
{
    _handler = handler;
}
