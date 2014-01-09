#include <QSettings>
#include <QJsonDocument>
#include <QJsonObject>

#include "websockethandler.h"

// Request
#include "Request/requestrefresh.h"
#include "Request/requestbuy.h"
#include "Request/requestsell.h"
#include "Request/requestlang.h"


WebsocketHandler::WebsocketHandler(QObject *parent) :
    QObject(parent)
{
    this->config = new QSettings();
    _langManager = NULL;
}

void WebsocketHandler::addRequest(Request *r)
{
    this->requestMap.insert(r->getName(),r);
}

void WebsocketHandler::createRequest()
{
    foreach(Request* r, requestMap)
    {
        delete r;
    }

    this->requestMap.clear();

    addRequest(new RequestRefresh());
    addRequest(new RequestBuy());
    addRequest(new RequestSell());
    addRequest(new RequestLang(_langManager));
}

void WebsocketHandler::startServer(int port, QtWebsocket::Protocol protocol)
{
    server = new QtWebsocket::QWsServer(this, protocol);
    if (! server->listen(QHostAddress::Any, port))
    {
            std::cout << tr("Error: Can't launch server").toStdString() << std::endl;
            std::cout << tr("QWsServer error : %1").arg(server->errorString()).toStdString() << std::endl;
    }
    else
    {
            std::cout << tr("Server is listening on port %1").arg(port).toStdString() << std::endl;
    }
    QObject::connect(server, SIGNAL(newConnection()), this, SLOT(processNewConnection()));
}

void WebsocketHandler::processNewConnection()
{
    QtWebsocket::QWsSocket* clientSocket = server->nextPendingConnection();

    Client* client = new Client();
    client->setWebsocketHandler(this);
    client->addSocket(clientSocket);

    _guestClients << client;

    connect(client, SIGNAL(frameReceived(QtWebsocket::QWsSocket*,QString)), this, SLOT(processMessage(QtWebsocket::QWsSocket*,QString)));
    connect(client, SIGNAL(disconnected(QtWebsocket::QWsSocket*)), this, SLOT(socketDisconnected(QtWebsocket::QWsSocket*)));
    connect(client, SIGNAL(pong(QtWebsocket::QWsSocket*,quint64)), this, SLOT(processPong(QtWebsocket::QWsSocket*,quint64)));

    std::cout << tr("Client connected").toStdString() << std::endl;
}

void WebsocketHandler::processMessage(QtWebsocket::QWsSocket *socket, QString frame)
{
    Client* client = dynamic_cast<Client*>(sender());
    if (socket == 0 || client == NULL)
    {
        return;
    }

    QJsonDocument doc;

    try{
        doc = QJsonDocument::fromJson(frame.toUtf8());
    }catch(QJsonParseError e){
        return socket->abort();
    }

    QJsonObject obj = doc.object();

    if(!obj.contains("type")){
        qWarning() << tr("Invalid request from") << socket->hostAddress().toString();
        socket->abort("Invalid request form");

    }else{
        QString request = obj.value("type").toString();

        if(this->requestMap.contains(request)){
            try{
                this->requestMap.value(request)->handle(client, obj);
            }catch(InvalidRequestException e){
                qWarning() << tr("Invalid request from") << socket->hostAddress().toString();
                socket->abort(e.what());
            }
        }else{
            qWarning() << tr("Unknow request %1 from").arg(request) << socket->hostAddress().toString() << frame;
            socket->abort();
        }
    }
}

void WebsocketHandler::processPong(QtWebsocket::QWsSocket* socket, quint64 elapsedTime)
{
    qDebug() << tr("ping: %1 ms").arg(elapsedTime);
    socket->write(QString("{\"type\":\"Hello World\"}"));
}

void WebsocketHandler::socketDisconnected(QtWebsocket::QWsSocket *socket)
{
    if (socket == 0)
    {
        return;
    }

    //clients.removeOne(socket);

    socket->deleteLater();

    qDebug() << tr("Client disconnected").toStdString().c_str();
}

void WebsocketHandler::setSqlHandler(SqlHandler* handler)
{
    this->sql = handler;
}

SqlHandler* WebsocketHandler::getSqlHandler()
{
    return this->sql;
}

void WebsocketHandler::setTranslationManager(TranslationManager *langManager)
{
    _langManager = langManager;
}

TranslationManager* WebsocketHandler::getTranslationManager()
{
    return _langManager;
}
