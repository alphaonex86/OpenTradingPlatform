#include <QSettings>
#include <QJsonDocument>
#include <QJsonObject>

#include "websockethandler.h"

#include "Request/requestrefresh.h"
#include "Request/requestbuy.h"
#include "Request/requestsell.h"



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

    connect(clientSocket, SIGNAL(frameReceived(QString)), this, SLOT(processMessage(QString)));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
    connect(clientSocket, SIGNAL(pong(quint64)), this, SLOT(processPong(quint64)));

    std::cout << tr("Client connected").toStdString() << std::endl;
}

void WebsocketHandler::processMessage(QString frame)
{
    QtWebsocket::QWsSocket* socket = qobject_cast<QtWebsocket::QWsSocket*>(sender());
    if (socket == 0)
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

        if(request == "message"){// test only
            socket->write(frame);// send back the object

        }else if(!this->requestMap.contains(request)){
            qWarning() << tr("Unknow request %1 from").arg(request) << socket->hostAddress().toString() << frame;
            socket->abort();

        }else{
            try{
                this->requestMap.value(request)->handle(NULL,obj);
            }catch(InvalidRequestException e){
                qWarning() << tr("Invalid request from") << socket->hostAddress().toString();
                socket->abort(e.what());
            }
        }
    }
}

void WebsocketHandler::processPong(quint64 elapsedTime)
{
    qDebug() << tr("ping: %1 ms").arg(elapsedTime);
}

void WebsocketHandler::socketDisconnected()
{
    QtWebsocket::QWsSocket* socket = qobject_cast<QtWebsocket::QWsSocket*>(sender());
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
